//类入门--基本的几个函数
#include <iostream>
#include <string>

using namespace std;

/**
 * 1、如果没有写构造函数，那么创建对象时，默认调用无参数构造函数，若声明了构造函数，则创建对象不会调用默认构造函数
 * 2、析构函数在调用delete后会自动调用，在析构函数中做是否的工作
 * 3、C语言中的malloc 与free 并不会调用构造和析构函数，
 * 4、new/delete 是一套  会调用构造函数 与 析构函数   【C++标准规范】
 *   malloc/free是一套  不调用构造函数 与 析构函数 【C的范畴，虽然不推荐，但是也是可以的】
 * 5、拷贝构造函数默认是有的，一旦我们自己写了拷贝构造函数就会覆盖默认的拷贝构造函数
 * 6、拷贝构造函数只有在创建对象时赋值才会被调用，如果对象创建好后再去赋值，则会走默认的赋值来完成
 * 7、如果定义的类的成员时对象成员，必须要在构造函数中这样初始化（构造函数后面 :+对象成员（内容））
 * 
 */
class Student {
public:
    //公有域
    Student() {
        //无参数构造函数，默认构造，可以不写
        cout << "无参数构造函数" << endl;
    }

    //带参数构造函数，
    Student(string name, int age) : name(name), age(age) {
        cout << "带参数构造函数" << endl;
        cout << "带参构造函数：" << "name=" << name << ",age=" << age << endl;
    }

    //拷贝构造函数
    Student(const Student &student) {
        cout << "拷贝构造函数" << endl;
        this->name = student.name;
        this->age = student.age;
        cout << "拷贝构造函数：" << "name=" << name << ",age=" << age << endl;
    }

    //析构函数，用在在对象被delete时，释放资源
    ~Student() {
        cout << "析构函数" << endl;
    }

protected:
    //半公有域
private:
    //私有域
    string name;
    int age;
};


int main() {

    /**
     * 常量指针、指针常量，常量指针常量 的深入理解
     * 1）常量指针：该指针指向的是一个“常量”，不允许修改“常量”的值，但是该指针可以重新指向
     *            const int*  number=....
     * 2)指针常量：该指针是一个常量，只能指向一个地方，不能重新指向，但是可以修改指向的内存的值
     *           int* const number=...
     * 3)常量指针常量：说明该指针是一个常量，该指针所指的也是一个“常量”，所以不能重新指向，也不能修改内存的值
     */
    int number = 100;
    int number2 = 200;
    //常量指针
    const int *numberP1 = &number;
//    *numberP1 = 999;//不允许修改指向的内存值
    numberP1 = &number2;//可重指向

    //指针常量
    int* const numberP2=&number;
//    numberP2=&number2;//不允许重指向
    *numberP2=666;//可可以指向的内存值

    //常量指针常量
    const int* const numberP3=&number;
//    numberP3=&number2;//不允许重指向
//    *numberP3=888;//不允许修改指向的内存的值




    /**
     * 4、误区
     * 指针的赋值不会执行构造函数，因为他仅仅是指针变量指向的问题，也就是指向同一个地址而已
     */
    cout << "误区----演示" << endl;
    Student *zhangsan = new Student("张三", 33);
    Student *lisi = zhangsan;
    cout << endl;


    /**
     * 3、拷贝构造函数
     */
    cout << "拷贝构造函数----演示" << endl;
    Student org_Student("leon", 18);
    Student copy_Sdu = org_Student;//会调用拷贝构造函数
    cout << endl;

    /**
     * 下面不会走拷贝构造函数，只会调用默认的赋值
     */
    Student copy_Sdu2;
    copy_Sdu2 = org_Student;
    cout << endl;

    /**
     * 2、带参构造函数
     */
    cout << "带参构造函数----演示" << endl;
    Student *leon_Student = new Student("leon", 18);
    delete leon_Student;
    leon_Student = NULL;
    cout << endl;



    /**
     * 1、默认构造函数与析构函数
     */
    cout << "默认构造函数与析构函数----演示" << endl;
    Student *student = new Student();
    delete student;
    student = NULL;


    return 0;
}

