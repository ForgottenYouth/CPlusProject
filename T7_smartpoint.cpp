//智能指针
#include <iostream>
#include <memory>
using namespace std;

//2
class Person2;
class Person1 {
public:
    weak_ptr<Person2> person2; // Person2智能指针  shared_ptr 引用计数+1
    ~Person1() {
        cout << "Person1 析构函数" << endl;
    }
};

class Person2 {
public:
    weak_ptr<Person1> person1;  // Person1智能指针  shared_ptr 引用计数+1
    ~Person2() {
        cout << "Person2 析构函数" << endl;
    }
};


//1
class Person{
public:

    ~Person() {
        cout << "Person 析构函数" << endl;
    }
};

int main(){
    cout<<"智能指针学习"<<endl;

    /**
     * 3、独占式智能指针
     */
     Person* person3=new Person();
    unique_ptr<Person> uniquePtr1(person3);
//    unique_ptr<Person> uniquePtr2=uniquePtr1;//不允许
    cout<<endl;
    cout<<endl;
    cout<<endl;

    /**
     * 2、智能指针循环依赖的问题(weak_ptr来解决)
     * 1）weak_ptr 没有引用计数
     * 2)循环依赖的问题是因为智能指针内部的引用计数减1后，计数不会变成0 ，导致释放的时候无法释放
     */
//    Person1 * person1 = new Person1(); // 堆区开辟
//    Person2 * person2 = new Person2(); // 堆区开辟
//    shared_ptr<Person1> sharedPtr1(person1); // +1 = 1
//    shared_ptr<Person2> sharedPtr2(person2); // +1 = 1
//
//    cout << "前 sharedPtr1的引用计数是:" << sharedPtr1.use_count() << endl;
//    cout << "前 sharedPtr2的引用计数是:" << sharedPtr2.use_count() << endl;
//
//    // 给Person2智能指针赋值
//    person1->person2 = sharedPtr2;
//    // 给Person1智能指针赋值
//    person2->person1 = sharedPtr1;
//
//    cout << "后 sharedPtr1的引用计数是:" << sharedPtr1.use_count() << endl;
//    cout << "后 sharedPtr2的引用计数是:" << sharedPtr2.use_count() << endl;


    /**
     * 1、智能指针
     *    引入库：#include <memory>
     *    格式：shared_ptr<类型> sharedPtr1(堆区开辟的对象指针);
     * 1）当我们在堆区开辟空间后，需要在函数弹栈之前释放堆区空间，经常因为业务逻辑导致忘记释放，这时候使用智能指针就会帮助我们释放（堆区开辟空间后马上加入到智能指针中去就可以了）
     * 2）智能指针是使用引用计数的方式进行管理对象的，当计数等于0 的时候，就会释放对象
     * 3) 原理：智能指针是栈成员，函数弹栈--->释放智能指针成员--->调用它的析构函数对对象进行释放(计数-1)
     */
//     Person* person=new Person();
//     shared_ptr<Person> sharedPtr(person);
    return 0;
}
