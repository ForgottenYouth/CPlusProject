#include <stdio.h>

int main(){

    const int number = 100;
    printf("C语言const number 的值是：%d, \n",number );
    int * numP = &number;
    *numP = 10000;
    printf("C语言通过指针修改常量的值：%d\n", number);
    return 0;
}

