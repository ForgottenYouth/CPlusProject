// 容器与谓词学习

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm> // 算法包

using namespace std;

//标准自定义谓词的格式
class Person {
public:
    string name;
    int id;

    Person(string name, int id) {
        this->name = name;
        this->id = id;
    }
};

struct doCompareAction {
public:
    bool operator()(const Person &person1, const Person &person2) {
        return person1.id > person2.id;
    }
};



// 回调函数 (功能够简单)
void showAction(int __first) {
    cout << "回调函数" << __first << endl;
}

//仿函数
class showActionObj{
public:
    int count =0;
    void operator()(int _first){
        cout<<"仿函数："<<_first<<endl;
        count++;
    }
};

int main() {
    cout << "容器与谓词学习" << endl;
    cout << endl;
    cout << endl;
    cout << endl;


    /**
     * 10、仿函数与回调函数
     *  1) 仿函数的扩展性强，回调函数比较简单
     */
    set<int> setaaaVar;

    setaaaVar.insert(10);
    setaaaVar.insert(20);
    setaaaVar.insert(30);
    setaaaVar.insert(40);
    setaaaVar.insert(50);
    setaaaVar.insert(60);

    // TODO 回调函数
    for_each(setaaaVar.begin(), setaaaVar.end(), showAction);
    showActionObj obj;
    obj= for_each(setaaaVar.begin(),setaaaVar.end(),obj);
    cout<<"调用次数："<<obj.count<<endl;

    /**
     * 9、multimap容器
     * 引入库：#include<map>
     * 格式：multimap<int ,string> multimapVar
     * 1) key 可以重复
     * 2）key重复的数据可分组
     * 3）key会排序
     * 4）value不会排序
     * 5) multimap 的查询，返回的结果需要自己做判断，否则会包含第一个找到的位置开始一直到map的end()
     */

    multimap<int ,string> multimapVar;

    //添加数据
    multimapVar.insert(make_pair(10, "十个1"));
    multimapVar.insert(make_pair(10, "十个2"));
    multimapVar.insert(make_pair(10, "十个3"));

    multimapVar.insert(make_pair(30, "三十1"));
    multimapVar.insert(make_pair(30, "三十3"));
    multimapVar.insert(make_pair(30, "三十2"));


    multimapVar.insert(make_pair(20, "二十1"));
    multimapVar.insert(make_pair(20, "二十2"));
    multimapVar.insert(make_pair(20, "二十3"));

    for (auto iteratorVar = multimapVar.begin(); iteratorVar != multimapVar.end() ; iteratorVar ++) {
        cout << iteratorVar->first << "," << iteratorVar->second << endl;
    }


    multimap<int, string>::iterator iteratorVar = multimapVar.find(20);
    while (iteratorVar != multimapVar.end()) {
        cout <<"查询的结果："<< iteratorVar->first << "," << iteratorVar->second << endl;

        // 需要自己做逻辑控制，不然会将后面的数据也都输出来
        iteratorVar++;

        if (iteratorVar->first != 20) {
            break;; // 循环结束
        }

        // 严谨性
        if (iteratorVar == multimapVar.end()) {
            break;; // 循环结束
        }
    }


    cout << endl;
    cout << endl;
    cout << endl;

    /**
     * 8、map容器
     *      引入库：#include<map>
     *      格式：map<int ,string> mapVar;
     *  1）map会对key排序
     *  2）默认key是不能重复
     *  3）map查询find函数的返回，如果没有找到会返回指向map结束的迭代器
     */
    map<int, string> mapVar;
    //添加数据
    mapVar.insert(map<int, string>::value_type(3, "third"));
    mapVar.insert(pair<int, string>(1, "first"));
    mapVar[4] = "four";
    mapVar.insert(make_pair(2, "second"));
    //下面来插入重复的数据
    const pair<map<int, string>::iterator, bool> mapResult = mapVar.insert(pair<int, string>(4, "four"));
    if (mapResult.second) {
        cout << "map容器插入重复的key成功" << endl;
    } else {
        cout << "map容器插入重复的key失败" << endl;
    }

    //map查询
    map<int, string>::iterator iterator1 = mapVar.find(5);
    if (iterator1 != mapVar.end()) {
        cout << "查询map元素key =5 的值是：" << iterator1->second << endl;
    } else {
        cout << "没有找到查询map元素key =5" << endl;
    }

    //输出
    for (map<int,string>::iterator iterator=mapVar.begin();iterator!=mapVar.end();iterator++) {
        cout<<"map容器的元素："<<iterator->first<<",value="<<iterator->second<<endl;

    }

    cout << endl;
    cout << endl;
    cout << endl;

    /**
     * 7、谓词 ===仿函数
     * 1） 系统的谓词基本上都是针对基本数据类型（如刚学习过的容器中的less<int>）,不支持对象比较
     * 2） 自定义对象比较的谓词：结构体格式的谓词
     * 3）谓词有几个参数，就是几元谓词
     */

    set<Person, doCompareAction> objSetVar;
    objSetVar.insert(Person("zhangsan", 2));
    objSetVar.insert(Person("lisi", 1));
    objSetVar.insert(Person("wangwu", 4));
    objSetVar.insert(Person("huangliu", 3));
    for (set<Person, doCompareAction>::iterator iterator = objSetVar.begin(); iterator != objSetVar.end(); iterator++) {
        cout << "自定义谓词：name=" << iterator->name << ", id=" << iterator->id << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;

    /**
     * 6、set
     *   引用库：#include<set>
     *   原理：内部是红黑树结构，会对存入的数据进行排序，不允许元素相同
     *   格式：set<int,less<int>>  setVar;
     *  1) set容器在插入相同元素时，不会报错，但是会在insert的返回值pair的第二个值中得到结果
     *  2）insert 函数返回值的第一个元素是迭代器，
     *  3)会自动对原始进行排序（默认是从小到大的排序）
     *  4）无法插入自定义的对象（set的自动排序，无法对自定义的对象进行排序。需要自定义仿函数来解决）
     */
    set<int, greater<int>> setVar;
    setVar.insert(1);
    setVar.insert(4);
    setVar.insert(0);
    setVar.insert(9);
    pair<set<int, greater<int>>::iterator, bool> result = setVar.insert(9);
    if (result.second) {
        cout << "插入数据成功" << endl;
    } else {
        cout << "失败了..." << endl;
    }

    //遍历访问
    for (auto it = setVar.begin(); it != setVar.end(); it++) {
        cout << "set容器中的原始：" << *it << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;

    /**
     * 5、list
     *   格式：list<T>
     *   1) C++的list 内部是采用链表的结构，而Java的ArrayList采用的是数组的结构
     *   2）不用通过角标去访问，也不能修改
     *   3) 元素数据可以重复
     */
    list<int> listVar;
    listVar.push_front(100);//前面插入
    listVar.push_front(200);
    listVar.push_front(123);
    listVar.push_back(44);//后面插入
    listVar.insert(listVar.begin(), 88);//
    listVar.insert(listVar.end(), 34);
    listVar.erase(listVar.begin());//删除
    for (list<int>::iterator it = listVar.begin(); it != listVar.end(); it++) {
        cout << "list元素数据：" << *it << endl;
    }

    cout << endl;
    cout << endl;
    cout << endl;

    /**
     * 4、优先级队列
     *     是一种特殊的队列，内部是对vector进行了一定的封装,具备自动排序的本领
     *     格式：priority_queue<int,vector<int>,less<int>>
     *          第一个参数：数据类型，第二个参数：内部需要一个vector,第三个参数：排序方式，
     *          后面两个参数可以不写，默认是从大到小
     *
     */
    priority_queue<int, vector<int>, less<int>> priorityQueue;
    priorityQueue.push(20);
    priorityQueue.push(19);
    priorityQueue.push(40);
    priorityQueue.push(13);
    priorityQueue.push(12);
    priorityQueue.push(11);
    while (!priorityQueue.empty()) {
        cout << "优先级队列输出元素:" << priorityQueue.top() << endl;
        priorityQueue.pop();
    }
    cout << endl;
    cout << endl;
    cout << endl;


    /**
     * 3、queue 队列 （先进先出----管道运输原理）
     *    引入库：#include <queue>
     *    格式：queue<类型>  队列名
     *
     *    1）有序容器
     *    2）不能使用下标访问，也没有迭代器，
     *    3）栈元素获取需要弹出栈，则栈内就不存在此元素了（特别注意）
     */
    queue<int> queueVar;

    queueVar.push(20);
    queueVar.push(40);
    queueVar.push(60);

    while (!queueVar.empty()) {
        cout << "queue 队列 :" << queueVar.front() << endl;
        queueVar.pop(); // 把前面的元素 给消费掉  【删除】
    }
    cout << endl;
    cout << endl;
    cout << endl;


    /**
     * 2、stack 栈  (先进后出，后进先出 FIFO----弹夹原理)
     *   格式：stack<类型>  栈容器名；
     *   引入库：#include <stack>
     *   1）栈容器是有顺序的，不能随意在指定位置压栈;
     *   2)不能使用下标访问，也没有迭代器，如果想要则需要自己去完成；
     *   3）栈元素获取需要弹出栈，则栈内就不存在此元素了（特别注意）
     */
    stack<int> stackVar;

    // 压栈（注意：stack无法指定那个位置去压栈）
    stackVar.push(30);
    stackVar.push(60);
    stackVar.push(90);

    //出栈
    while (!stackVar.empty()) {
        cout << "栈容器的元素是:" << stackVar.top() << endl;//取栈顶元素
        stackVar.pop();//弹出并删除
    }
    cout << endl;
    cout << endl;
    cout << endl;




    /**
     * 1、vector向量(类似于map)
     *       #include <vector> 引入库，
     *       格式：vector<类型>  向量容器名；
     *     1) 原理：内部是封装了一个可以动态变化大小的数组作为容器，能够存放任务类型的数据，访问成员时需要使用迭代器访问
     *     2）vector2.begin()  与 vector.end() 是获取向量容器签名或后面的迭代器
     *     3)向量的添加vector.insert(迭代器，value),删除（vector.erase(迭代器)），读取：迭代器
     *     4）在对向量元素进行操作的时候可以通过begin ,end获取到迭代器进行位置的便宜来操作
     *     5)front() 与 back()默认获取第一个或最后一个元素的可读写引用，
     */

//    vector<int> vector;//可以不传参数
//    vector<int> vector(10); //代表大小
    vector<int> vector2(10, 1);//代表大小、默认值

    //添加
    vector2.insert(vector2.begin() + 5, 100);
    vector2.insert(vector2.end(), 199);

    //查询, 此处的auto会自动进行类型推导
    for (auto iterator = vector2.begin(); iterator != vector2.end(); iterator++) {
        cout << "vector容器的元素是：" << *iterator << endl;
    }

    //获取第一个元素的可读写引用
    cout << vector2.front() << endl;
    vector2.front() = 888;
    cout << vector2.front() << endl;

    //删除
    vector2.erase(++vector2.begin());
    for (auto iterator = vector2.begin(); iterator != vector2.end(); iterator++) {
        cout << "删除后的vector容器的元素是：" << *iterator << endl;
    }

    return 0;
}
