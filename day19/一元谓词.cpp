#include <iostream>
using namespace std;
#include <vector>
#include <string.h>
#include <algorithm>

template <typename T>
class IsDiv
{
public:
    IsDiv(const T &divisor)
    {
        m_divisor = divisor;
    }

    bool operator()(T &t)
    {
        return (t % m_divisor == 0);
    }

private:
    T m_divisor;
};

main()
{
    vector<int> vec;
    for(int i=10;i<33;i++){
        vec.push_back(i);
    }

    int a=4;
    IsDiv<int> isDiv(a);
    vector<int>::iterator it = find_if(vec.begin(), vec.end(), IsDiv<int>(4));
    if(it != vec.end()){
        cout << "find:" << *it << endl;
    }

    cout << endl;
    printf("hello..\n");
}
