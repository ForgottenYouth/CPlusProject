//运算符重载
#include <iostream>

/**
 * 1、C++语言中的运算符基本上都在写在类内部的，这样可以直接访问私有成员
 * 2、内部运算符重载时，将操作符的参数设置为const+ 引用,一是防止修改，二是引用不会引起浪费性能的问题（只是别名）
 * 3、前置++ 和后置++运算符重载时，为了区分需要在函数名（）中加入int,例如：operator ++(int) 代表后置++ ；operator ++()  代表前置++
 * 4、输入输出预算法重载（友元函数），需要支持连续调用，那就需要类似于RxJava的思路返回this
 */

using namespace std;

class Paper {
private:
    int length;
    int width;

public:

    //输出运算符重载
    friend ostream &operator<<(ostream &_START, Paper paper) {
        _START << "width = " << paper.width << ",length=" << paper.length << endl;
        return _START;
    }

    friend istream &operator>>(istream &_START, Paper& paper) {
        _START >> paper.width;
        _START >> paper.length;
        return _START;
    }

    /**
    * 内部运算符重载，可以直接访问私有成员
    */
    Paper operator-(const Paper &paper) {
        int tempWidth = this->width - paper.width;
        int tempLength = this->length - paper.length;
        return Paper(tempWidth, tempLength);
    }

    /**
     * 前置++
     */
    void operator++() {
        this->width++;
        this->length++;
    }

    /**
     * 后置++
     */
    void operator++(int) {
        this->width++;
        this->length++;
    }

public:


    Paper(int width, int length) : width(width), length(length) {
    }

    int getLength() {
        return this->length;
    }

    int getWidth() {
        return this->width;
    }

    void setLength(int length) {
        this->length = length;
    }

    void setWidth(int width) {
        this->width = width;
    }


};

/**
 * 外部运算符重载
 * @param p1
 * @param p2
 * @return
 */
Paper operator+(Paper p1, Paper p2) {
    int width = p1.getWidth() + p2.getWidth();
    int length = p1.getLength() + p2.getLength();
    Paper totalPaper(width, length);
    return totalPaper;

}

int main() {

    Paper whitePaper(100, 200);
    Paper redPaper(333, 444);
    Paper totalPaper = whitePaper + redPaper;
    cout << "-----------------外部运算符重载-----------------" << endl;
    cout << "外部运算符+重载后的结果是：width=" << totalPaper.getWidth() << ",length=" << totalPaper.getLength() << endl;

    cout << "-----------------内部运算符重载-----------------" << endl;
    Paper innerPaper = totalPaper - whitePaper;
    cout << "内部运算符-重载后的结果是：width=" << innerPaper.getWidth() << ",length=" << innerPaper.getLength() << endl;


    cout << "-----------------前置后置++运算符重载-----------------" << endl;
    innerPaper++;
    cout << "内部运算符后置++重载后的结果是：width=" << innerPaper.getWidth() << ",length=" << innerPaper.getLength() << endl;
    ++innerPaper;
    cout << "内部运算符前置++重载后的结果是：width=" << innerPaper.getWidth() << ",length=" << innerPaper.getLength() << endl;


    cout << "-----------------输入输出运算符重载-----------------" << endl;
    cin >> innerPaper;
    cout <<"输出用户输入："<< innerPaper;

    return 0;
}
