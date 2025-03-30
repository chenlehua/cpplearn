#include "stdlib.h"
#include "string.h"
#include <stdio.h>

char **getMem(int num)
{
    int i = 0;
    char **p2 = NULL;
    char tmpBUf[100];
    p2 = (char **)malloc(sizeof(char *) * num);
    if (p2 == NULL)
    {
        return NULL;
    }

    for (i = 0; i < 5; i++)
    {
        p2[i] = (char *)malloc(sizeof(char) * 100); // char buf[100]
        memset(p2[i], 0, 10);
        sprintf(p2[i], "%d%d%d", i + 1, i + 1, i + 1);
    }
    return p2;
}

void freeMem(char **p2, int num)
{
    int i = 0;
    for (i = 0; i < num; i++)
    {
        if (p2[i] != NULL)
        {
            free(p2[i]);
            p2[i] = NULL;
        }
    }

    if (p2 != NULL)
    {
        free(p2);
    }
}

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
            if (strcmp(myArray[i], myArray[j]) < 0)
            {
                char *temp = myArray[i]; // 交换的是数组元素 交换的是指针的值,改变指针的指向
                myArray[i] = myArray[j];
                myArray[j] = temp;
            }
        }
    }
}

// 二级指针做输入第三种内存模型
int main()
{
    int i = 0, j = 0;
    char **p2 = NULL;
    int num = 5;
    char tmpBUf[100];
    p2 = getMem(num);

    printMyArray11(p2, num);
    // 排序 交换的是指针
    //  for(i=0;i<num;i++)
    //  {
    //      for(j=0;j<num-i-1;j++)
    //      {
    //          if(strcmp(p2[j],p2[j+1])<0)
    //          {
    //              char *tmp = p2[j];
    //              p2[j] = p2[j+1];
    //              p2[j+1] = tmp;
    //          }
    //      }
    //  }

    // 排序
    printf("排序\n");

    // 排序 交换的是内存
    sortMyArray11(p2, num);

    printMyArray11(p2, num);
    // 释放内存
    freeMem(p2, num); //p2是一个野指针
    printf("hello..\n");
}
