#include <iostream>
using namespace std;
#include <vector>
#include <string.h>

// 所有容器提供的都是值语义，而非引用语义。容器执行插入元素的操作时，内部实施拷贝动作。
// 所以STL容器内存储的元素必须能够被拷贝（必须提供拷贝构造函数，重载=操作符）；
class Teacher
{
public:
    Teacher(char *name, int age)
    {
        m_pname = new char[strlen(name) + 1];
        strcpy(m_pname, name);
        m_age = age;
    }

    ~Teacher()
    {
        if (m_pname != NULL)
        {
            delete[] m_pname;
            m_pname = NULL;
            m_age = 0;
        }
    }

    // Teacher t2=t1;
    //  1.拷贝构造函数
    Teacher(const Teacher &obj)
    {
        m_pname = new char[strlen(obj.m_pname) + 1];
        strcpy(m_pname, obj.m_pname);
        m_age = obj.m_age;
    }

    // 重载=号操作符
    // t3=t2=t1;
    Teacher &operator=(const Teacher &obj)
    {
        if (this != &obj)
        {
            if (m_pname != NULL)
            {
                delete[] m_pname;
                m_pname = NULL;
                m_age = 0;
            }
            m_pname = new char[strlen(obj.m_pname) + 1];
            strcpy(m_pname, obj.m_pname);
            m_age = obj.m_age;
        }
        return *this;
    }

    void printT()
    {
        cout << "name:" << m_pname << " age:" << m_age << endl;
    }

protected:
private:
    char *m_pname;
    int m_age;
};

main()
{
    Teacher t1("t1", 31);

    vector<Teacher> v1;
    v1.push_back(t1); // 把t1拷贝了一份，存入到容器中

    printf("hello..\n");
}
