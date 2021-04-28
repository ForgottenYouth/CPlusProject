//类的详解
#include <iostream>
#include <string>

/**
 * 1) 类的static（成员与函数）通过类名+::来访问，不属于对象
 * 2）类的static 成员不能直接赋值,会报错。例如： static int age = 9;
 * 3）静态的属性必须要初始化，然后再实现（规则）
 * 4) 静态方法不能调用非静态方法和成员;非静态函数可以调用静态或非静态的方法和成员；
 * 5）静态成员和方法在.h中声明时需要static，在.cpp文件中不需要,和普通方法一样了；
 *
 * 6）友元函数（好朋友关系，所以可以访问私有成员）：在.h中声明时，需要用friend来声明，在.cpp中则不需要friend ，也不需要类名+::  ,只需要函数名，返回，参数即可
 * 7)友元关系不传递（例如：A和B是好朋友，B和C是好朋友，那么A和C就不一定是好朋友）
 */

using namespace std;

// 静态demo
class Student {
public:
    static int age;
    char *sex;

    static void show() {
        age = 100;
//        update();  //静态函数不能调用非静态函数，
//        sex="m";  //静态函数不能访问非静态的成员
    }

    void update() {
        int value = age * 10;
        show();
    }
};

//友元demo

class ImageView {

private:
    int width = 100;
    int height = 110;
    string url = "hello";

    friend class Activity;//Activity类是ImageVIew的好友
};

class Activity {
private:
    ImageView img;
    int index;

public:
    void getInfos() {
        cout << "通过友元访问对象的私有成员：width= " << img.width << ",height=" << img.height << ",url=" << img.url << endl;
    }

    // 定义友元函数 (声明，没有实现)
    friend void updateInfos(Activity &activity, int width, int height, string url);
};


void updateInfos(Activity &activity, int width, int height, string url) {
//    activity->img.width=width;//不传递关系
    activity.index = 100;
    cout << "友元函数访问私有成员index=" << activity.index << endl;
}

int main() {

    Activity activity;
    activity.getInfos();

    updateInfos(activity, 0, 0, "");

    return 0;
}
