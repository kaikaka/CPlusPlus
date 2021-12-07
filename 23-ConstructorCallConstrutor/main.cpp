#include <iostream>

using namespace std;

//构造器之间的相互调用

class Person {
public:
    int m_age;
    int m_height;
    //调用其他构造函数要这样写(语法糖)
    Person():Person(10,20)  {

    }

    Person(int age,int height) {
        this->m_age = age;
        this->m_height = height;
    }
};

int main()
{
    Person person;
    cout << person.m_age << endl;
    cout << person.m_height << endl;
    return 0;
}
