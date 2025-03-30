#include "stdlib.h"
#include "string.h"
#include <stdio.h>

// 通过数组下标 和指针
int main()
{
    int i = 0;
    char *p = NULL;

    char buf5[128] = "abcdefg";

    for (i = 0; i < strlen(buf5); i++)
    {
        printf("%c ", buf5[i]);
    }

    p = buf5; //buf5代表数组首元素的地址,是只读的常量  是一个常量指针
    for (i = 0; i < strlen(buf5); i++)
    {
        // printf("%c ", *(p + i));
        printf("%c ", *(buf5 + i));
    }

    printf("hello..\n");
}
