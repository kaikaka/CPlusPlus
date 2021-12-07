#include <iostream>

using namespace std;

class Car {
public:
    int m_price;
    Car() {
        m_price = 0;
        cout << "Car::Car()" << endl;
    }
    ~Car() {
        cout << "Car::~Car()" << endl;
    }
};

class Person {
private:
    int m_age;
    Car *m_car;
public:
    Person() {
        m_age = 0;
        m_car = new Car ();
        cout << "Person()" << endl;
    }

    ~Person() {
        //析构时 释放内存
        delete m_car;
        cout << "~Person()" << endl;
    }

};

int main()
{
    {
        Person person;
    }
        /*
Car::Car()
Person()
Car::~Car()
~Person()
调用顺序：
1.调用父类的构造函数
2.调用子类的构造函数
3.调用子类的析构函数
4.调用父类的析构函数

*/
getchar();
    return 0;
}
