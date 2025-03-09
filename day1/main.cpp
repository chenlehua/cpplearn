// #include <iostream>

// int main(int, char**){
//     std::cout << "Hello, from cpplean!\n";
// }

#include "stdlib.h"
#include "string.h"
#include <stdio.h>

void printArray(int a[], int num)
{
    int i = 0, j = 0;
    for (int i = 0; i < num; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// 数组做函数参数，传递的是数组的首地址；
// 结论：把数组的内存首地址和数据的有效长度传给被调用函数
//  void sortArray(int a[], int num)
void sortArray(int *a, int num)
{
    int i = 0, j = 0;
    // 选择排序
    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    int num = 0;
    int a[] = {33, 654, 4, 455, 6, 33, 4};
    num = sizeof(a) / sizeof(a[0]);

    printArray(a, num);

    sortArray(a, num);

    printArray(a, num);

    printf("\n");
    printf("hello..\n");
}
