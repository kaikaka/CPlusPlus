#include <iostream>

using namespace std;

class Person {
public:
    int m_age;
    int m_id;
    int m_height;
    void run(Person *person) {
        cout << "Person::run -" << person->m_age << endl;
    }
    void run() {
        //this 指针存储着函数调用者的地址
        //this 指向了函数调用者
//        cout << "Person::run() -" << this->m_age << endl;
        this->m_age = 3;
        this->m_id = 9;
    }
    void display() {
      cout << "id = " << m_id
                << ", age = " << m_age
                << ", height = " << m_height << endl;
    }
};

void test() {
    Person person;
    person.m_id = 10;
    person.m_age = 20;
    person.m_height = 30;
    person.display();

    Person *p = &person;
    p->m_id = 10;
    p->m_age = 10;
    p->m_height = 10;
    p->display();
}

int main()
{
    Person person;
    person.run();
    test();
    return 0;
}
