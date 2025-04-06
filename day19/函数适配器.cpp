#include <iostream>
using namespace std;
#include <vector>
#include <string.h>
#include <algorithm>
#include <functional>

class IsGreat
{
public:
    IsGreat(int i)
    {
        this->m_num = i;
    }

    bool operator()(int &num)
    {
        if (num > m_num)
        {
            return true;
        }
        return false;
    }

private:
    int m_num;
};

main()
{

    vector<int> v1;
    for (int i = 1; i < 10; i++)
    {
        v1.push_back(i);
    }

    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    int num1 = count(v1.begin(), v1.end(), 3);
    cout << "num1:" << num1 << endl;

    // 通过谓词求大于2的个数
    int num2 = count_if(v1.begin(), v1.end(), IsGreat(2));
    cout << "num2:" << num2 << endl;

    // 通过预定义的函数对象求大于2的个数
    int num3 = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(), 2));
    cout << "num3:" << num3 << endl;

    // 求奇数的个数
    int num4 = count_if(v1.begin(), v1.end(), bind2nd(modulus<int>(), 2));
    cout << "num4:" << num4 << endl;

    // 求偶数的个数
    int num5 = count_if(v1.begin(), v1.end(), not1(bind2nd(modulus<int>(), 2)));
    cout << "num5:" << num5 << endl;

    modulus<int> m;
    int a = m(4, 2);
    cout << "a:" << a << endl;

    cout << endl;
    printf("hello..\n");
}
