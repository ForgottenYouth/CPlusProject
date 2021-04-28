//手写智能指针
#include <iostream>
#include "CustomPtr.h"

using namespace std;

class Person{
public:
    ~Person(){
        cout<<"析构函数调用"<<endl;
    }
};

int main(){
    
    /**
     * 手写智能指针
     */

    Person* person=new Person();
    Person* person1=new Person();

    /**
     * 智能指针的构造函数，计数+1
     */
    cout<<"-----1-------"<<endl;
    CustomPtr<Person> customPtr(person);
    cout<<"构造函数执行后："<<customPtr.use_count()<<endl;

    /**
     * 拷贝构造函数   计数+1
     */
    cout<<"-----2-------"<<endl;
    CustomPtr<Person> customPtr1(customPtr);
    cout<<"拷贝构造函数执行后："<< customPtr1.use_count()<<endl;

    /**
     * 拷贝构造函数，计数+1
     */
    cout<<"-----3-------"<<endl;
    CustomPtr<Person> customPtr2=customPtr;
    cout<<customPtr2.use_count()<<endl;

    /**
     * 运算符重载  计数+1（会先创建一个对象，然后再运算符重载中释放已经创建好的默认对象，然后再赋值）
     */
    cout<<"-----4-------"<<endl;
    CustomPtr<Person> customPtr3;
    customPtr3=customPtr;
    cout<<customPtr3.use_count()<<endl;//

    /**
     * 运算符重载，计数+1
     * 特别注意：如果在运算符重载中，不释放智能指针中的源对象person1 ,会导致person1对象成为野对象，无法释放，必须要手动释放delete
     */

    cout<<"-----5-------"<<endl;
    Person* person2=new Person();
    CustomPtr<Person> customPtr4(person2);
    CustomPtr<Person> customPtr5(person1);
    customPtr5=customPtr4;
    cout<<customPtr5.use_count()<<endl;

    return 0;
}
