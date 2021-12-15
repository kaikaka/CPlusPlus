#include <iostream>

using namespace std;

class Person {
    virtual void run() {}
};

class Student : public Person {

};

class Car {

};

void test_const() {
    const Person *p1 = new Person ();
    // const_cast一般用于去除const属性，将const转换成非const
    Person *p2 = const_cast<Person *>(p1);
    Person *p3 = (Person *)p1;
    //p2 /p3 这种写法是一致的
}

void test_dynamic() {
    Person *p1 = new Person ();
    Person *p2 = new Student ();

    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;

    Car *c1 = (Car *)p1;
    Car *c2 = dynamic_cast<Car *>(p2);
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
//dynamic_cast 一般用于多态类型的转换，有运行时安全检测
//    Student *stu1 = dynamic_cast<Student *>(p1); // 不安全
//    Student *stu2 = dynamic_cast<Student *>(p2); // 安全

    Student *stu1 = (Student *) p1; // 不安全 但没检测出来
    Student *stu2 = (Student *) p2; // 安全

    cout << "stu1 = " << stu1 << endl;
    cout << "stu2 = " << stu2 << endl;
}

void test_static() {
    Person *p1 = new Person ();
    const Person *p2 = p1;
    int a = 10;
    //static_cast 基本类型转换
    double d = static_cast<double>(a);
    double f = double(a);
    cout << a << endl;
    cout << d << endl;
    cout << f << endl;
}

int main()
{
    test_const();
    test_dynamic();
    test_static();
    //reinterpret_cast属于比较底层的强制转换，没有任何类型检查和格式转换，仅仅是简单的二进制数据拷贝
    int *p = reinterpret_cast<int *>(0x100);
    cout << p << endl;

    return 0;
}
