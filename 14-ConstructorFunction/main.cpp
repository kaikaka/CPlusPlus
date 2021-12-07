#include <iostream>

using namespace std;

class Person {
public:
    int m_age;
    int m_money;
    int m_width;
    //在mac环境下的c++(QT，XCode)编译器，会把分配到栈空间的偶数的成员变量初始化为1
    Person() {
        m_age = 0;
        cout << "Person()" << endl;
    }

    Person(int age,int money) {
        m_age = age;
        m_money = money;
        cout << "Person(int age, int money)" << endl;
    }

    Person (int age) {
        m_age = age;
        cout << "Person(int age)" << endl;
    }

    void display() {
        cout << "age is " << m_age << ", money is " << m_money << ", width is " << m_width << endl;
    }
};

class Person1 {
public:
    int m_age;
    Person1() {
        cout << "Person1::Person1()" << endl;
    }
    void run() {
        cout << "Person1::run() - " << m_age << endl;
    }
};

class Person2 {
public:
    int m_age;
    Person2() {
        m_age = 0;
        cout << "Person2()" << endl;
    }
    Person2(int age) {
        m_age = age;
        cout << "Person(int age)" << endl;
    }
};

Person2 g_person0;
Person2 g_person1();
Person2 g_person2(10);


void test() {

    Person person;
    person.display();

    Person person1(10,20);
    person1.display();

    Person person2(20);
    person2.display();

    Person person3(30);
    person3.display();
}

void test2() {
//    Person1 *p = new Person1;
//    delete  p;

    //malloc不会调用构造函数
    Person1 *p1 = (Person1 *)malloc(sizeof (Person));
    p1->m_age = 10;
    p1->run();
    free(p1);
}

void test3() {
    Person2 person0;//调用person() 构造函数
    Person2 person1(); //函数声明
    Person2 person2(20);//Person(int)

    cout << "test3" << endl;
    cout << &person0 << endl;
    cout << &person1 << endl;
    cout << &person2 << endl;

    Person2 *p0 = new Person2; //Person() 构造函数
    Person2 *p1 = new Person2 (); //Person()
    Person2 *p2 = new Person2 (30); //Person(Int)
    cout << p0 << endl;
    cout << p1 << endl;
    cout << p2 << endl;
}

int main()
{
//    test();
//    test2();
    test3();
    return 0;
}
