// C++ 11 之后出现的线程 pthread
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <queue>

using namespace std;

// 异步线程  相当于Java的Thread.run函数一样
void *customPthreadTask(void *pVoid) {
    // C++转换static_cast  转换指针操作的
    int *number = static_cast<int *>(pVoid); // pVoid==number int的地址，所以我用int*接收，很合理
    cout << "异步线程执行了:" << *number << endl;

    for (int i = 0; i < 10; ++i) {
        cout << "run:" << i << endl;
        sleep(1);
    }
    return 0; // 必须返回，否则有错误，不好查询
}


//互斥锁部分
queue<int> data;//全局的存储队列
pthread_mutex_t mutex;//定义一个互斥锁，不允许有野指针
void *task(void *pVoid) {
    pthread_mutex_lock(&mutex); // 锁住
    int* number;
    number=static_cast<int *>(pVoid);
    cout << "当前线程的标记是:" << *number << endl;
    if (!data.empty()) {
        printf("获取队列的数据:%d\n", data.front());
        data.pop(); // 删除
    } else {
        printf("没有数据了\n");
    }
    sleep(0.1);
    pthread_mutex_unlock(&mutex); // 解锁
    return 0;
}

//条件变量+互斥锁
#include "SafeQueue.h"

SafeQueue<int> sq;

// TODO 模拟演示 消费者
void *getMethod(void *) {
    while (true) {
        int value;
        sq.get(value);
        printf("消费者get 得到的数据:%d\n", value);

        // 你只要传入 -1 就结束当前循环
        if (-1 == value) {
            break;
        }
    }
    return 0;
}

// TODO 模拟演示 生产者
void *setMethod(void *) {
    while (true) {
        int value;
        printf("请输入你要生成的信息:\n");
        cin >> value;
        sq.add(value);
        if (value == -1) {
            break;
        }
    }
    return 0;
}

int main() {

    cout << "c++ 自带的线程pthread" << endl;
    /**
     * 4、条件变量+互斥锁 == Java版本的（notify 与 wait 操作）
     *  pthread_cond_broadcast====Java notifyAll 所有的
     *  pthread_cond_signal=====  Java notify 单个的
     */
    pthread_t pthreadGet;
    pthread_create(&pthreadGet, 0, getMethod, 0);
    pthread_t pthreadSet;
    pthread_create(&pthreadSet, 0, setMethod, 0);

    pthread_join(pthreadGet, 0);
    pthread_join(pthreadSet, 0);

    /**
     * 3、互斥锁（相当于java的synchronize）
     * 1)不允许有野指针，所有必须要初始化
     *
     */
    //初始化
    pthread_mutex_init(&mutex, NULL);

    // 给队列 初始化数据 手动增加数据进去
    for (int i = 10001; i < 10111; ++i) {
        data.push(i);
    }

    //定义10个线程
    pthread_t pthreadIDArray[20];
    for (int i = 0; i < 20; ++i) {
        pthread_create(&pthreadIDArray[i], 0, task, &i);

        // 不能使用 join，如果使用（就变成顺序的方式，就没有多线程的意义了，所以不能写join）
        // pthread_join(pthreadIDArray[i], 0);
    }

    sleep(20);

    // 销毁 互斥锁
    pthread_mutex_destroy(&mutex);

    /**
     * 2、分离线程与非分离线程的区别和应用场景
     * 1）分离线程：各个线程都是自己运行自己的，互不相关。例如：main函数结束，就全部结束，不会等待异步线程。
     *            （多线程情况下使用）
     * 2）非分离线程：线程之间有协作的能力，例如：main函数会等待异步线程执行完后，再执行后面的代码
     *            （协作、顺序指向的场景）
     */


    /**
     * 1、pthread_create参数说明：
     * 第一个参数：线程ID
     * 第二个参数：线程属性，用0即可
     * 第三个参数：函数指针（耗时函数名）
     * 第四个参数：函数指针的参数
     *
     *  * 特别说明：
     * 1) c++中的线程和main函数默认是互不相关的，也就是说main函数弹栈后不管子线程是否完成，就会结束子线程（允许异常）
     * 2) 可以使用join来让子线程完成后再执行join后面的代码，直至main函数弹栈
     * 3）千万不要让main函数睡眠的方式等待异步线程
     */
//    int number = 9527;
//    pthread_t pthreadID; // 线程ID，每个线程都需要有的线程ID
//    pthread_create(&pthreadID, 0, customPthreadTask, &number);
//    pthread_join(pthreadID,0);

    return 0;
}


