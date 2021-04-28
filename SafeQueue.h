//
// Created by shiwenliang on 2021/4/26.
//

#ifndef CPLUGPROJECT_SAFEQUEUE_H
#define CPLUGPROJECT_SAFEQUEUE_H
#include <iostream>
#include <string>
#include <pthread.h>
#include <string>
#include <queue>
using namespace std;

template<typename  T>

class SafeQueue{
private:
    queue<T> queue;
    pthread_mutex_t  mutex; // 定义互斥锁（不允许有野指针）
    pthread_cond_t cond; // 条件变量，为了实现 等待 读取 等功能 （不允许有野指针）
public:
    SafeQueue(){
        // 初始化 互斥锁
        pthread_mutex_init(&mutex, 0);

        // 初始化 条件变量
        pthread_cond_init(&cond, 0);
    }
    ~SafeQueue() {
        // 回收 互斥锁
        pthread_mutex_destroy(&mutex);

        // 回收 条件变量
        pthread_cond_destroy(&cond);
    }
public:
    void add(T t){
        // 为了安全 加锁
        pthread_mutex_lock(&mutex);

        queue.push(t); // 把数据加入到队列中
        // 告诉消费者，我已经生产好了
        // pthread_cond_signal(&cond) // Java notify 单个的
        pthread_cond_broadcast(&cond); // Java notifyAll 所有的的

        // 解锁
        pthread_mutex_unlock(&mutex);
    }
    void get(T & t){
        // 为了安全 加锁
        pthread_mutex_lock(&mutex);

        while (queue.empty()) {
            cout << "等待中.." << endl;
            pthread_cond_wait(&cond, &mutex); // 相当于 Java的 wait 等待了[有可能被系统唤醒]
        }

        // 证明被唤醒了
        t = queue.front(); // 得到 队列中的元素数据 仅此而已
        queue.pop(); // 删除元素

        // 解锁
        pthread_mutex_unlock(&mutex);
    }
};

#endif //CPLUGPROJECT_SAFEQUEUE_H
