#include <iostream>

using namespace std;

class Person {
public:
  int m_id;
int m_age;
int m_height;
void display() {
    cout << "id =" << m_id << ", age = " << m_age << ", height =" << m_height << endl;
}
};

//Person person;

int main()
{
    //这个person对象分配在栈空间
    Person person;
    person.m_id = 1;
    person.m_age = 2;
        person.m_height = 3;

        cout << "&person == " << &person << endl; //person的首地址实际上就是默认第一个成员变量的地址
        cout << "&person.m_id == " << &person.m_id << endl;
        cout << "&person.m_age == " << &person.m_age << endl;
        cout << "&person.m_height == " << &person.m_height << endl;
        person.display();
    return 0;
}
