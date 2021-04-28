//汇聚C++中的一些特殊知识点

#include <iostream>
#include <stdarg.h>
#include <cstring>

using namespace std;

/**
 * 可变参数的求和
 * @param count  指定可变参数的数量的参考值，用于在变量取出可变参数时越界，导致取出来的是系统的随机值
 * @param ...
 * @return
 */

int va_sum(int count, ...) {
    int sum = 0;
    va_list vp;
    //第一个参数是可变参考的开始动作，第二个参数是数量参考值
    va_start(vp, count);
    //遍历取值
    for (int i = 0; i < count; ++i) {
        int element = va_arg(vp, int);
        cout << "第" << i << "个元素的值是：" << element << endl;
        sum += element;
    }
    va_end(vp);
    return sum;
}


template<typename T, typename P>
void fun(T t, P p) {
    cout << "模板函数:t=" << t << ",p=" << p << endl;
}

//模板函数重载
template<typename T>
void fun(T t) {
}

void fun(int age, string name) {
    cout << "普通函数:age=" << age << ",name=" << name << endl;
}


class Pig {
public:
    char *name;

    Pig(const char *str)
            : name(new char[strlen(str) + 1]) {
        strcpy(name, str);
    }

    Pig(const Pig &s)
            : name(s.name) {}


    Pig &operator=(const Pig &s) {
        if (this != &s) {
            name = s.name;
        }
        return *this;
    }

    ~Pig() {
        if (name) {
//            delete[] name;
        }
        name = NULL;
    }
};


// 类型转换
class Person {
public:
    string name = "hello";
public:
    virtual void show() {
        cout << "Person show" << endl;
    }
};

class Worker : public Person {
public:
    void show() {
        cout << "Person show" << endl;
    }
};


int main() {
    /**
     * 4.四大转换
     * 1) const_cast:将常量指针转化成非常量指针
     *    原理：将常量指针指向的内存地址赋值给新的指针变量，所有修改的内存地址里面的值
     * 2）static_cast: (编译期)静态转化（看左边，左边是什么类型，后续操作就调用左边类型的成员）
     *    指针相关的转化，父子类之间的转化都可以使用static_cast
     * 3）dynamic_cast:（运行期）动态转化
     *    a）父类的函数必须为虚函数
     *    b）子类转父类可以，父类不能转子类
     *    c)多态转换的返回值，有则成功，null则转换失败
     *
     * 4) reinterpret_cast 强制转换(笔者没有转换成功，编译报错)
     *     a)静态转换可以做的 ，强制转换都可以
     *     b)用在任意指针（或引用）类型之间的转换；以及指针与足够大的整数类型之间的转换；从整数类型（包括枚举类型）到指针类型，无视大小
     *
     */
//     reinterpret_cast
    Person * person2 = new Person();
    long personLong = reinterpret_cast<long>(person2); // 把对象变成数值

    //dynamic_cast
    Person *person = new Worker();
    Worker *worker = dynamic_cast<Worker *>(person);
    if (worker) {
        cout << "转换成功" << endl;
    } else {
        cout << "转换失败" << endl;
    }


    //static_cast
    int n = 88;
    void *pVoid = &n;
    int *number = static_cast<int *>(pVoid);
    *number = 99;
    cout << *number << endl;

    Person * person1 = new Person();
    Worker* worker1=static_cast<Worker*>(person1);
    worker1->show();



    //const_cast
    const Person *p1 = new Person();
    Person *p2 = const_cast<Person *>(p1);
    p2->name = "hello world";
    cout << p1->name << endl;


    /**
     * 3、深浅拷贝
     * 1）浅拷贝（值拷贝）：将一个对象的值复制到另外一个对象中去，两个对象共享一份实体，这就是浅拷贝。 浅拷贝存在如下两个问题：
     *    a)浅拷贝存在同一个内存被释放多次的问题。
     *    b)两个指针指向同一个地址，当其中一个指针修改其内存的值时，会导致另外一个指针的值也随之改变。
     *
     * 2)深拷贝（值与地址拷贝）：另外开辟一个新的内存空间，将源内存中的值拷贝到新的内存空间，其实就是另个独立的内存，只不过他们的值是一样的而已，
     *    这样在释放内存的时候，就会各自释放各自的。
     *
     * 3)自定义拷贝构造函数：如果有堆成员，必须采用深拷贝
     */
    cout << endl;
    cout << endl;
    cout << "--------------" << endl;
    Pig blackPig("black");
    Pig redPig(blackPig);
    cout << "redPig的地址：" << redPig.name << ",------blackPig的地址：" << blackPig.name << endl;
    cout << "redPig=" << redPig.name << ", blackPig=" << blackPig.name << endl;

    (*redPig.name) = 'r';
    cout << "(*redPig.name)='r'修改后的redPig的地址：" << &redPig.name << ",-----blackPig的地址：" << &blackPig.name << endl;
    cout << "(*redPig.name)='r'修改后的值：redPig=" << redPig.name << ",-----blackPig=" << blackPig.name << endl;


    cout << endl;
    cout << endl;
    cout << endl;


    /**
     * 2、模板函数（相当于java的泛型）
     *   格式：template <typename T,P>    T,P 就相当于定义的类型
     *   1)用于来解决因为参数类型不同，而功能相同需要重写很多函数的问题（代码复用）
     *   2)使用方法：方法名<数据类型>（参数类型），数据类型也可以不写，会自动完成类型推导
     *   3）编译期对模板函数会进行两次编译，a) 编译函数模板本身，进行语法检查等，b)对参数替换后的代码进行，其实及时普通函数的编译一样
     *   4）模板函数针对使用的类型不同，会产生不同的函数（相当于编译器帮我们自己重载了该函数）
     *   5）模板函数支持多个不同的类型参数：template <typename T，typename P,typename,Y>
     *   6)可以使用<>空模板来限定编译器只能匹配模板函数，如果不限定会默认匹配普通函数
     *   7）模板函数可以重载
     */
    fun<int, int>(1, 2);//指定模板类型(从左到右)
    fun("leon");//调用重载的模板函数
    fun<>("hello", "world");//限定默认匹配模板函数
    fun(88, "pig weight");//默认匹配普通函数


    /**
     * 1、函数的可变参数
     * 1)需要使用#include <stdarg.h> 来支持可变参数
     * 2)va_start  与 va_end函数成对出现，类似于文件操作（打开，关闭）
     * 3)可变参数函数必须有一个指定的count ，用于遍历取值，防止越界
     */
    cout << "-------------可变参数学习-----------------" << endl;
    int sum = va_sum(5, 6, 2, 3, 4, 5);
    cout << "求和的结果是：" << sum << endl;

    return 0;
}

