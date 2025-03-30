#include "stdlib.h"
#include "string.h"
#include <stdio.h>


//报错，问题的本质是 指针的步长不一样 指针所指向的内存空间的数据类型不一样
// void printMyArray12(char **myArray, int num)
// {
//     int i = 0;
//     for (i = 0; i < num; i++)
//     {
//         // printf("%s\n", myArray[i]);
//         printf("%s \n", *(myArray + i));
//     }
// }

void printMyArray12(char myArray[10][30], int num)
{
    int i = 0;
    for (i = 0; i < num; i++)
    {
        // printf("%s\n", myArray[i]);
        printf("%s \n", *(myArray + i));
    }
}

void sortMyArray12(char myArray[10][30], int num){
    int i = 0, j = 0;
    char tmpBUF[30];
    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (strcmp(myArray[i], myArray[j]) > 0)
            {
                strcpy(tmpBUF, myArray[i]); // 交换的是内存块
                strcpy(myArray[i], myArray[j]);
                strcpy(myArray[j], tmpBUF);
            }
        }
    }
}

// 二级指针做输入第二种内存模型
int main()
{
    int num = 4;

    char myBUF[30];

    char myArray[10][30] = {"aaaaaaa", "cccc", "bbbbbbbb", "1111111"};

    //编译器只会关心有10行，每行30列 ，myArray+1 会跳过30个字节，多维数组的本质
    {
        int len1 = sizeof(myArray);
        int len2 = sizeof(myArray[0]);
        int size = len1 / len2;
        printf("len1 = %d, len2 = %d, size = %d\n", len1, len2, size);

    }

    // 打印
    printf("排序前\n");
    printMyArray12(myArray, num);

    // 排序
    sortMyArray12(myArray, num);

    // 打印
    printf("排序后\n");
    printMyArray12(myArray, num);

    printf("hello..\n");
}
