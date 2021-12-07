#include <iostream>

using namespace std;

class Person {
public:
    int m_age;
    int m_height;
    //1.构造函数
//    Person(int age,int height) {
//        m_age = age;
//        m_height = height;
//    }
    //2.初始化列表方式
    Person(int age = 0,int height = 0):m_age(age),m_height(height) {
        cout << "Person(int age = 0,int height = 0):m_age(age),m_height(height)" << endl;
    }
};

int main()
{
    Person person1;
    Person person2(17);
    Person person(18, 180);

    cout << person1.m_age << endl;
    cout << person1.m_height << endl;

    cout << person2.m_age << endl;
    cout << person2.m_height << endl;

    cout << person.m_age << endl;
    cout << person.m_height << endl;
    return 0;
}
