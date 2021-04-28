#include <iostream>

using namespace std;//命名空间

namespace CustomNameSpace{
    namespace InnerLayer{
        void innerShow(){
            cout<<"内部嵌套的命名空间函数innerShow()被调用"<<endl;
        }
    }
    void show(){
        cout<<"自定义命名空间里面的show()被调用"<<endl;
    }
}

/**
 * C++与C语言的比较
 * 1、C++是标准的面向对象的语言，   C语言是面向过程的语言
 * 2、C++的标准支持库#include <iostream> ,   C语言的标准支持库#include<stdio.h>
 * 3、C++可以运行C语言，可以调用C语言，反之:C语言不能调用C++
 * 4、C++ 增加了命名空间的特性
 * 5、C++支持函数重载，而C语言不支持函数重载
 * 6、C和C++中的bool 值，都是非0即true ,否则是false
 * 7、栈区开辟的空间在函数弹栈会释放掉，堆区开辟的空间需要在使用结束后手动释放掉
 */

//直接参数交换--吧成功
void switchNumber(int number1, int number2) {
    cout<<"number1 的地址是："<<&number1<<",number2的地址是："<<&number2<<endl;
    int temp = number1;
    number1 = number2;
    number2 = temp;
}

//指针交换
void switchNumber1(int* number1, int* number2) {
    cout<<"number1 的地址是："<<number1<<",number2的地址是："<<number2<<endl;
    int temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}

void switchNumber2(int& number1, int& number2) {
    cout<<"number1 的地址是："<<number1<<",number2的地址是："<<number2<<endl;
    int temp = number1;
    number1 = number2;
    number2 = temp;
}

//常量引用
typedef struct {
    char name[20];
    int age;
}Student;

void insertStudent(const Student & student)
{
//    Student  student1={"bbbbb",2};
//    student=student1;//常量引用不能修改
    cout << student.name << "," << student.age << endl;
}

int add(int number1,int number2){

}

int add(int number1,int number2,int number3=0)
{
//1、默认值参数必须在无默认值的参数后面
//2、有二义性
}

int add(bool  a ,bool  b)
{
//此函数无二义性
}

int main() {

    /**
     * 4.函数重载的二义性
     * 1)、若重载函数的参数类型相同，参数数量不同，但是多出的参数有默认值，或者是所有的参数都有默认值，这样会导致函数二义性的问题
     * 2)、函数重载，有默认值的参数必须全部在无默认值的参数后面
     * 3)、参数数据类型不一致时，不会导致二义性
     */
//     add(1,2);


    /**
     * 3、引用
     * 1)、C++的引用其实用就是别名或者绰号的意思，其实和他所引用的对象都是指向同一块地址
     * 2)、常量应用（const int& ） :该引用变量变成只读
     */
    int number1 = 100;
    int number2 = 200;
    cout<<"*****switchNumber直接交换值*******"<<endl;
    cout << "交换之前的两个数：number1=" << number1 << " 的地址："<<&number1<<", number2=" << number2 << " 的地址："<<&number2<< endl;
    switchNumber(number1, number2);
    cout << "交换之后的两个数：number1=" << number1<< " 的地址："<<&number1 << ", number2=" << number2 << " 的地址："<<&number2<< endl;
    cout<<endl;
    cout<<endl;

    cout<<"*****switchNumber1  指针交换*******"<<endl;
    cout << "交换之前的两个数：number1=" << number1 << " 的地址："<<&number1<<", number2=" << number2 << " 的地址："<<&number2<< endl;
    switchNumber1(&number1, &number2);
    cout << "交换之后的两个数：number1=" << number1<< " 的地址："<<&number1 << ", number2=" << number2 << " 的地址："<<&number2<< endl;
    cout<<endl;
    cout<<endl;


    cout<<"*****switchNumber2 引用交换*******"<<endl;
    cout << "交换之前的两个数：number1=" << number1 << " 的地址："<<&number1<<", number2=" << number2 << " 的地址："<<&number2<< endl;
    switchNumber2(number1, number2);
    cout << "交换之后的两个数：number1=" << number1<< " 的地址："<<&number1 << ", number2=" << number2 << " 的地址："<<&number2<< endl;
    cout<<endl;
    cout<<endl;

    Student  student={"aaaa",1};
    insertStudent(student);

    /**
     * 输出结果：
     * *****switchNumber直接交换*******
     * 交换之前的两个数：number1=100 的地址：0x61fe1c, number2=200 的地址：0x61fe18
     * number1 的地址是：0x61fdf0,number2的地址是：0x61fdf8
     * 交换之后的两个数：number1=100 的地址：0x61fe1c, number2=200 的地址：0x61fe18
     *
     * *****switchNumber1  指针交换*******
     * 交换之前的两个数：number1=100 的地址：0x61fe1c, number2=200 的地址：0x61fe18
     * number1 的地址是：0x61fe1c,number2的地址是：0x61fe18
     * 交换之后的两个数：number1=200 的地址：0x61fe1c, number2=100 的地址：0x61fe18
     *
     *
     * *****switchNumber2 引用交换*******
     * 交换之前的两个数：number1=200 的地址：0x61fe1c, number2=100 的地址：0x61fe18
     * number1 的地址是：200,number2的地址是：100
     * 交换之后的两个数：number1=100 的地址：0x61fe1c, number2=200 的地址：0x61fe18
     */


    /**
     * 2、真假常量
     *  C语言中的常量其实是个假常量，可以通过指针修改；而C++中的常量则不然,编译不通过或者运行报错
     */
//    const int number = 100;
//    printf("C语言const number 的值是：%d, \n",number );
//    int * numP = &number;
//    *numP = 10000;
//    printf("C语言通过指针修改常量的值：%d\n", number);
    /**
     * 输出的结果：
     * C语言const number 的值是：100,
     * C语言通过指针修改常量的值：10000
     */

    /**
     * 1、自定义命名空间
     * 1)命名空间使用namesapce + 名字来进行自定义
     * 2）命名空间内部可以嵌套N层自定义命名空间,通过::进行多层嵌套调用
     * 3)通过可以使用using namesapce 来引入，调用空间内的函数时，就不需要命名空间名称+:: 来限定
     */
     CustomNameSpace::InnerLayer::innerShow();
     CustomNameSpace::show();


    /**
     * 比较
     */
    cout << "欢迎进入C++学习" << endl;//C++中的打印输出,  没有引用命名空间时，需要使用命名空间来限定
    printf("我是用C语言的printf打印的\n");//C语言中的输出
    return 0;
}
