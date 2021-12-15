#include <iostream>

using namespace std;

//隐式构造
class Person {
    int m_age;
public:
    Person() {
        cout << "Person() - " << this << endl;
    }
    Person (int age):m_age(age) {
        cout << "Person (int age) - " << this << endl;
    }

    Person (const Person &person) {
        cout << "Person(const Person &person) - " << this << endl;
    }

    ~Person() {
        cout << "~Person() - " << this << endl;
    }

    void display() {
        cout << "display() - age is " << m_age << endl;
    }
};

void test1(Person person) {

}

Person test2() {
    return 40;
}

int main()
{
    cout << "------1------" << endl;
    test1(30);//当对象是参数时，这样写也会默认调用Person的构造函数
    cout << "------1------" << endl;
    test2();//当对象是返回值时，也会隐式地调用构造函数
    cout << "------2------" << endl;

    Person p1; //调用无参的构造函数
    p1 = 40; //调用int 参数的构造函数

    return 0;
}
