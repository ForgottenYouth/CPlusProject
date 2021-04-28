/**
 * 类的继承
 */
#include <iostream>

using namespace std;

/**
 * 2、C++多继承（允许多个父类）
 *  1）多继承，若多个父类拥有想到的成员或方法，编译时会导致二义性（ error: request for member 'show' is ambiguous）
 *   a) 重写二义性的方法，
 *   b）通过.来指明父类，再通过:: 来调用二义性的方法     格式：对象.父类名::函数名
 *   c) 虚继承：为多个父类重名的成员和方法提取到一个新的祖父类中（即 虚基类）
 */

//虚继承
class GrandParent {
public:
    char *name;
    int age;
    char *familyName;
};

class Father : virtual public GrandParent {

};

class Mother : virtual public GrandParent {

};

class Child : public Father, public Mother {

};


//多继承
class Base1 {
public:
    void show() {
        cout << "Base1::show()" << endl;
    }
};

class Base2 {
public:
    void show() {
        cout << "Base2::show()" << endl;
    }
};

class MainActivity : public Base1, public Base2 {
public:

    /**
     * 覆盖父类的方法
     */
    void show() {
        cout << "mainActivity::show()" << endl;
    }
};


/**
 * 1、默认的的继承关系是private；可以显式指定继承关系,public ,private ,protected
 *  1)private 继承：子类内部仅能访问父类非私有的成员和方法，子类对象不能访问父类的所有成员和方法
 *  2)protected 继承：子类内部仅能访问父类非私有的成员和方法，子类对象不能访问父类的所有成员和方法
 *  3)public 继承：子类内部仅能访问父类非私有的成员和方法,子类对象可以访问父类的public成员和方法
 *  总结：继承后，子类内部只能范文父类的非私有成员和方法，外部之类对象只有在public继承时可以访问父类的public成员和方法，其他都不可以访问
 *2、继承关系的构造析构函数的调用顺序
 * 构造顺序：先调用父类的，再调用子类
 * 析构顺序：先子类，再父类
 */

class Person {
private:
    char *name;
protected:
    int age;
public:
    void show() {

    }
};

class Student : public Person {

private:
    char *course;

public:
    void showInfos() {
    }
};


//全部是纯虚函数---类似于interface
class BaseBaseActivity{
public:
    virtual void onCreate()=0;
    virtual int getLayoutID()=0;
};

//有纯虚函数---抽象类
class BaseActivity : public BaseBaseActivity {
public:
    virtual void onCreate() {
        cout << "BaseActivity:onCreate()" << endl;
    }
    //纯虚函数，如果加上这句话，子类没有实现该纯虚函数，那么该子类是无法实例化的
    virtual int getLayoutID()=0;
};


//
class HomeActivity : public BaseActivity {
public:
    //重载：静态多态
    void onCreate() override {
        cout << "MainActivity:onCreate()--override" << endl;
    }
    //纯虚函数的实现
    int getLayoutID(){
        return 1;
    }
};

class PersonActivity : public BaseActivity {
public:

    //重写了：动态多态
    void onCreate() {
        cout << "PersonActivity:onCreate()" << endl;
    }

    //纯虚函数的实现
    int getLayoutID(){
        return 2;
    }
};

void gotoActivity(BaseActivity *baseActivity) {
    baseActivity->onCreate();
}


int main() {

    /**
     * 抽象类与纯虚函数
     * 1）C++ 没有抽象类，但是有纯虚函数，就相当于Java的抽象类
     * 2）纯虚函数是必须要继承的，而虚函数则不是必须继承
     * 3）纯虚函数和虚函数的区别是：纯虚函数没有实现，直接赋值=0 即可；虚函数是有实现的
     * 4）如果子类没有实现纯虚函数，那么该子类是无法实例化的（即：子类就是抽象类，编译期就会报错）
     * 5）纯虚函数的格式：virtual void getLayoutID()=0;
     * 6）如果一个类的所有的方法都是纯虚函数，那么这个类就等价于java的接口，
     */

    /**
     * 多态（虚函数）：程序在允许期间才能确定调用哪个类的函数 ，这就是动态多态的范畴
     * 1.概念：父类的引用指向子类的对象，同一个方法有不同的实现，重写（动态多态：运行时确定）和 重载（静态多态：编译期确定）
     * 2、java 默认支持多态的，而C++的多态默认是关闭掉了的， 那我们需要需要在父类的函数上加上virtual 关键字即可打开
     * 3、创建子类实例时，可以用父类对象来接受
     *
     */
    BaseActivity * homeActivity = new HomeActivity();
    BaseActivity * personActivity = new PersonActivity();
    gotoActivity(homeActivity);
    gotoActivity(personActivity);
    delete homeActivity;
    delete personActivity;

    cout << endl;
    cout << endl;
    cout << endl;


    /**
     * 虚继承
     */
    Child child;
    child.name = "xiaoming";
    cout << "虚继承后，child 的name=" << child.name << endl;

    /**
     * 2 多继承
     */
    MainActivity mainActivity;
    mainActivity.show();
    mainActivity.Base1::show();

    /**
     * 1 继承
     */
    Student student;
    student.showInfos();

    return 0;
}
