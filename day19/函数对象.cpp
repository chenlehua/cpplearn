#include <iostream>
using namespace std;
#include <vector>
#include <string.h>
#include <algorithm>

// 函数对象，类重载了()操作符
//  1.函数对象是一个类，类中重载了()操作符
//  2.函数对象可以像函数一样被调用
//  3.函数对象可以作为参数传递给STL算法
//  4.函数对象可以保存状态
template <typename T>
class ShowElement
{
public:
    ShowElement()
    {
        n = 0;
    }

    void operator()(T &t)
    {
        n++;
        printN();
        cout << t << " ";
    }

    void printN()
    {
        cout << "n=" << n << endl;
    }

private:
    int n;
};

// 函数模板
template <typename T>
void FuncShowElement(T &t)
{
    cout << t << " ";
}

// 普通函数
void FuncShowElement2(int &t)
{
    cout << t << " ";
}

// 函数对象和普通函数的区别
// 函数对象是属于类对象，能突破函数的概念，能保持调用状态信息
main()
{
    int a = 10;
    ShowElement<int> showEle;
    showEle(a); // 函数对象的()的执行 很像一个函数 //仿函数

    FuncShowElement<int>(a);
    FuncShowElement2(a); // 普通函数的调用

    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    cout << endl;
    for_each(v1.begin(), v1.end(), ShowElement<int>()); // 匿名函数对象
    cout << endl;
    for_each(v1.begin(), v1.end(), FuncShowElement2); // 通过普通回调函数，谁使用for_each谁去填写回调函数的入口地址
    cout << endl;

    ShowElement<int> show1;
    // 不能打印状态，for_each算法的函数对象的传递 是元素值传递，不是引用传递
    for_each(v1.begin(), v1.end(), show1); // 通过函数对象的方式
    show1.printN();                       

    // 能打印状态
    show1 = for_each(v1.begin(), v1.end(), show1); // 通过函数对象的方式
    show1.printN();                                // 通过函数对象的方式，能保持状态信息，不能打印状态


    //分清楚stl算法返回的值是迭代器 还是谓词（函数对象） 是stl算法入门的重要点

    cout << endl;
    printf("hello..\n");
}
