#include <iostream>
using namespace std;
#include <vector>
#include <string.h>
#include <algorithm>

// 二元函数对象
template <typename T>
class SumAdd
{
public:
    T operator()(T &t1, T &t2)
    {
        return t1 + t2;
    }

private:
};

// 普通函数
void FuncShowElement2(int &t)
{
    cout << t << " ";
}

bool MyCompare(const int &a, const int &b)
{
    return a > b; // 从大到小
}

main()
{

    vector<int> v1, v2;
    vector<int> v3;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    v2.push_back(2);
    v2.push_back(4);
    v2.push_back(6);

    v3.resize(10);

    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), SumAdd<int>());

    for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
    {
        cout << *it << endl;
    }

    vector<int> v4(10);
    for (int i = 0; i < 10; i++)
    {
        int tmp = rand() % 100;
        v4[i] = tmp;
    }

    for_each(v4.begin(), v4.end(), FuncShowElement2);
    cout << endl;

    sort(v4.begin(), v4.end(), MyCompare);

    for_each(v4.begin(), v4.end(), FuncShowElement2);

    cout << endl;
    printf("hello..\n");
}
