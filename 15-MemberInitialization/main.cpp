#include <iostream>

using namespace std;

//成员变量初始化
class Person {
public:
    int m_age;
    Person() {
        memset(this,0,sizeof (Person));
    }
};

//全局区，成员变量初始化为0
Person g_person;

void test() {
    //栈空间：没有初始化成员变量
    Person person;

    //堆空间：在gcc/llvm上 编译器会优化，默认初始化，在vc++环境上
    Person *p0 = new Person; //在vc++上，不会初始化成员变量
    Person *p1 = new Person ();//在vc++上，成员变量初始化为0

    cout << g_person.m_age << endl;
//    cout << person.m_age << endl;
    cout << p0->m_age << endl;
    cout << p1->m_age << endl;
    delete  p0;
    delete  p1;
}

int main()
{
    test();
    Person *p = new Person[3] {};
    cout << p[0].m_age << endl;

    return 0;
}
