#include "stdlib.h"
#include "string.h"
#include <stdio.h>

void printMyArray11(char **myArray, int num)
{
    int i = 0;
    for (i = 0; i < num; i++)
    {
        // printf("%s\n", myArray[i]);
        printf("%s \n", *(myArray + i));
    }
}

void sortMyArray11(char **myArray, int num)
{
    int i = 0, j = 0;
    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (strcmp(myArray[i], myArray[j]) > 0)
            {
                char *temp = myArray[i];  // 交换的是数组元素 交换的是指针的值,改变指针的指向
                myArray[i] = myArray[j];
                myArray[j] = temp;
            }
        }
    }
}

// 二级指针做输入第一种内存模型
int main()
{
    int i = 0, j = 0;
    int num = 0;
    // 数组 数组中的每一个元素是指针  指针数组
    char *myArray[] = {"aaaaaaa", "cccc", "bbbbbbbb", "1111111"};

    // 打印
    num = sizeof(myArray) / sizeof(myArray[0]);
    printf("排序前\n");
    printMyArray11(myArray, num);

    // 排序
    sortMyArray11(myArray, num);

    printf("排序后\n");
    printMyArray11(myArray, num);

    printf("hello..\n");
}
