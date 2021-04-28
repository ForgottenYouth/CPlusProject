//
// Created by shiwenliang on 2021/4/26.
//

#ifndef CPLUGPROJECT_CUSTOMPTR_H
#define CPLUGPROJECT_CUSTOMPTR_H
#pragma once

#include <iostream>

using namespace std;

template<typename T>
class CustomPtr {
private:
    T *object;
    int *count;

public:
    CustomPtr() {
        count = new int(1);
        object = NULL;
    }

    CustomPtr(T *t) : object(t) {
        count = new int(1);
    }

    //拷贝构造函数
    CustomPtr(const CustomPtr<T> &p) {
        ++(*p.count);
        object = p.object;
        count = p.count;
    }

    //运算符重载
    CustomPtr<T> &operator=(const CustomPtr<T> &p) {
        //因为运算符重载，左侧的对象已经创建好了，所以需要释放
        if (--(*count) == 0) {
            if (object) {
                delete object;
            }
            delete count;
        }

        ++(*p.count);

        object = p.object;
        count = p.count;
        return *this;
    }

    ~CustomPtr() {
        cout<<"智能指针的析构函数"<<endl;
        if (--(*count) == 0) {
            if (object) {
                delete object;
            }
            delete count;
            object = NULL;
            count = NULL;
        }
    }


    int use_count() {
        return *(this->count);
    }

};

#endif //CPLUGPROJECT_CUSTOMPTR_H
