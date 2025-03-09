#include <stdio.h>

typedef struct Teacher2
{
    int age;
    char name[64];
} Teacher2;

struct Teacher
{
    int age;
    char name[64];
};

typedef int u32;

// 定义一个数组类型  数组指针 数组类型和数组指针类型的关系
int main()
{
    int a;     // 告诉c编译器分配4个字节的内存
    int b[10]; // 告诉c编译器分配40个字节的内存
    printf("b:%zu, b+1:%zu,&b:%zu,&b+1:%zu\n", (size_t)b, (size_t)(b + 1), (size_t)&b, (size_t)(&b + 1));
    // b代表数组首地址，b+1代表数组首地址+4个字节，&b代表整个数组的地址，&b+1代表数组首地址+40个字节

    printf("sizeof(b):%lu,sizeof(a):%lu\n", sizeof(b), sizeof(a));

    struct Teacher t1;
    Teacher2 t2;

    printf("u32:%lu\n", sizeof(u32));

    printf("hello..\n");
}
