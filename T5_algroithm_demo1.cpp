//系统的算法包实战
#include <iostream>
#include <set> // stl包
#include <vector>
#include <algorithm> // 算法包

using namespace std;


//仿函数
class __F {
public:
    void operator()(string __first) {
        cout << "自定义for_each一元谓词:" << __first << endl;
    }
};

class __unary_op {
public:
    int operator()(int __first) {
        __first += 100;
        cout << "自定义transform的仿函数:" << __first << endl;
        return __first;
    }
};

class __pred {
public:
    int number;

    __pred(int number) : number(number) {}

    bool operator()(const int value) {
        return number = value;
    }
};

class __pred2 {
public:
    int number;

    __pred2(int number) : number(number) {}

    bool operator()(const int value) {
        return value < number;
    }
};

int main() {

    cout << "---算法包实战--------" << endl;

    /**
     * 10、replace 替换元素
     * 在指定的容器范围内，替换全部的旧值为新值
     */
    vector<int> vectorVar9;
    vectorVar9.push_back(11);
    vectorVar9.push_back(23);
    vectorVar9.push_back(30);
    vectorVar9.push_back(44);
    vectorVar9.push_back(55);
    replace(vectorVar9.begin()+3,vectorVar9.end(),55,58);
    for (auto it=vectorVar9.begin();it!= vectorVar9.end();it++) {
        cout<<"执行replace函数后的容器元素："<<*it<<endl;
    }
    cout<<endl;

    /**
     * 9、copy 将1个容器里面的元素复制到另外一个容器里面
     */
    vector<int> vectorVar8;
    vectorVar8.push_back(1);
    vectorVar8.push_back(2);
    vectorVar8.push_back(3);
    vector<int> vectorResult8(vectorVar8.size());
    copy(vectorVar8.begin(),vectorVar8.end(),vectorResult8.begin());
    for (auto it=vectorResult8.begin();it!= vectorResult8.end();it++) {
        cout<<"执行copy函数后的  结果容器   元素："<<*it<<endl;
    }
    cout<<"##################"<<endl;
    for (auto it=vectorResult8.begin();it!= vectorResult8.end();it++) {
        cout<<"执行copy函数后的 原  容器元素："<<*it<<endl;
    }
    cout<<endl;

    /**
     * 8、random_shuffle随机打乱元素的顺序
     * 原理：通过随机数与（当前位置与起始位置相减+1） 进行 %操作后，找到要切换顺序的位置，然后再将这两个位置的值进行交换
     */
    vector<int> vectorVar7; // vector默认是没有排序功能的，默认输出： 65 53 84
    vectorVar7.push_back(1);
    vectorVar7.push_back(2);
    vectorVar7.push_back(3);
    vectorVar7.push_back(4);
    vectorVar7.push_back(5);
    vectorVar7.push_back(6);
    vectorVar7.push_back(7);
    random_shuffle(vectorVar7.begin(), vectorVar7.end());
    for (auto iterator = vectorVar7.begin(); iterator != vectorVar7.end(); iterator++) {
        cout << "随机打乱顺序后的结果是：" << *iterator << endl;
    }

    cout << endl;

    /**
     * 7、sort 排序
     * 1）排序可以不需要传入第三个参数，系统默认提供了一个比较从小到大的仿函数；
     * 2）第三个参数也可以传入自定义或内置的模板函数
     */
    vector<int> vectorVar6;
    vectorVar6.push_back(10);
    vectorVar6.push_back(30);
    vectorVar6.push_back(20);
    sort(vectorVar6.begin(), vectorVar6.end());

    for (auto itVar = vectorVar6.begin(); itVar != vectorVar6.end(); itVar++) {
        cout << "容器排序后的结果：" << *itVar << endl;
    }
    cout << endl;


    /**
     * 6、merge 合并
     *
     * 原理：按照容器的开始与结束位置，循环遍历两个容器的元素，并进行从小到大的排序后，进行拷贝，
     */
    vector<int> vectorVar5;
    vectorVar5.push_back(10);
    vectorVar5.push_back(60);
    vectorVar5.push_back(30);
    vectorVar5.push_back(40);

    vector<int> vectorVar4;
    vectorVar4.push_back(50);
    vectorVar4.push_back(90);
    vectorVar4.push_back(70);
    vectorVar4.push_back(80);

    vector<int> vectorResult;
    vectorResult.resize(vectorVar5.size() - 2 + vectorVar4.size());
    merge(++vectorVar4.begin(), --vectorVar4.end(), vectorVar5.begin(), vectorVar5.end(), vectorResult.begin());
    for (auto iterator = vectorResult.begin(); iterator != vectorResult.end(); iterator++) {
        cout << "合并后的容器元素是：" << *iterator << endl;
    }

    cout << endl;


    /**
     * 5、count_if 统计某一个元素在容器中出现的次数
     */
    vector<int> vectorVar1;
    vectorVar1.push_back(1);
    vectorVar1.push_back(2);
    vectorVar1.push_back(3);
    vectorVar1.push_back(2);
    vectorVar1.push_back(4);
    vectorVar1.push_back(6);
    vectorVar1.push_back(8);
    vectorVar1.push_back(1);
    int num = count(vectorVar1.begin(), vectorVar1.end(), 2);
    cout << "统计元素是2的个数：" << num << endl;

    //使用函数适配器
    num = count_if(vectorVar1.begin(), vectorVar1.end(), bind2nd(less<int>(), 3));
    cout << "函数适配器模式---统计小于元素3的个数：" << num << endl;

    num = count_if(vectorVar1.begin(), vectorVar1.end(), __pred2(3));
    cout << "自定义仿函数模式---统计小于元素2的个数：" << num << endl;
    cout << endl;

    /**
     * 4、find 没有自定义仿函数;find_if有自定义仿函数
     *  1)原理：是对find_if的封装,通过迭代器指针移动来完成查询工作
     *  2）find_if 是通过对容器迭代器的位置++进行遍历查询
     */
    vector<int> vectorVar3;
    vectorVar3.insert(vectorVar3.begin(), 10000);
    vectorVar3.insert(vectorVar3.begin(), 20000);
    vectorVar3.insert(vectorVar3.begin(), 30000);
    vectorVar3.insert(vectorVar3.begin(), 40000);
    auto findResult = find(vectorVar3.begin(), vectorVar3.end(), 10000);
    auto findIfReslut = find_if(vectorVar3.begin(), vectorVar3.end(), __pred(10000));
    if (findResult != vectorVar3.end()) {
        cout << "findResult找到了" << endl;
    } else {
        cout << "findResult未找到" << endl;
    }

    if (findIfReslut != vectorVar3.end()) {
        cout << "findIfReslut找到了" << endl;
    } else {
        cout << "findIfReslut未找到" << endl;
    }

    cout << endl;

    /**
     * 3、transform  变化操作  类似于RxJava中的变化操作符
     * 1) 用于将集合的元素修改值；
     * 2) 定义带有返回值的一元仿函数（参数类型和返回值类型需要根据容器元素的数据类型来确定）
     * 3）将修改后的值赋值给当前迭代器的位置(也可以自定义个容器用于接收返回的值)
     */
    vector<int> vectorVar2;
    vectorVar2.insert(vectorVar2.begin(), 10000);
    vectorVar2.insert(vectorVar2.begin(), 20000);
    vectorVar2.insert(vectorVar2.begin(), 30000);
    vectorVar2.insert(vectorVar2.begin(), 40000);
    cout << "---在当前容器中进行修改--------" << endl;
    transform(vectorVar2.begin(), vectorVar2.end(), vectorVar2.begin(), __unary_op());

    cout << "---将修改的结果另外存储--------" << endl;
    vector<int> vectorReslut(vectorVar2.size());
    transform(vectorVar2.begin(), vectorVar2.end(), vectorReslut.begin(), __unary_op());

    cout << endl;

    /**
     * 2、for_each遍历
     * 源码： for_each(_InputIterator __first, _InputIterator __last, _Function __f)  两个迭代的位置（模板函数），一个仿函数
     * 仿函数的写法：根据源码可以推导出来仿函数需要一个参数（参数类型与容器的元素类型一致）
     */
    vector<string> vectorVar;
    vectorVar.insert(vectorVar.begin(), "10000");
    vectorVar.insert(vectorVar.begin(), "60000");
    vectorVar.insert(vectorVar.begin(), "40000");
    vectorVar.insert(vectorVar.begin(), "20000");
    vectorVar.insert(vectorVar.begin(), "50000");
    vectorVar.insert(vectorVar.begin(), "30000");
    for_each(vectorVar.begin(), vectorVar.end(), __F());
    cout << endl;

    /**
     * 1、函数适配器 ：bind1st (将第一个参数适配传递给equal_to()函数),bind2nd(将第二个参数适配传递传递给equal_to函数)
     *  1）find_if参数说明：第一个参数是开始的位置，第二个参数是结束的位置，第三个是仿函数（equal_to()）
     */
    set<string, less<string>> setVar;
    setVar.insert("AAAA");
    setVar.insert("BBBB");
    setVar.insert("CCCC");
    set<string, less<string>>::iterator iteratorResult =
            find_if(setVar.begin(),
                    setVar.end(),
                    bind1st(equal_to<string>(), "1111")
                    /*bind2nd(equal_to<string>(), "BBBB")*/);

    if (iteratorResult != setVar.end()) {
        cout << "查找到了" << endl;
    } else {
        cout << "没有查找到" << endl;
    }
    return 0;
}
