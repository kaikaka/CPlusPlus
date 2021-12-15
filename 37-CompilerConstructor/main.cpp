#include <iostream>

using namespace std;
//编译器自动生成的构造函数
//C++的编译器在某些特定的情况下，会给类自动生成无参的构造函数，比如
//成员变量在声明的同时进行了初始化
//有定义虚函数
//虚继承了其他类
//包含了对象类型的成员，且这个成员有构造函数(编译器生成或自定义)
//父类有构造函数(编译器生成或自定义)
//总结一下
//对象创建后，需要做一些额外操作时(比如内存操作、函数调用)，编译器一般都会为其自动生成无参的构造函数


class Student {
public:
    int m_price;
    void run() {

    }
};

class Car {
public:
    int m_price = 0;
};

class Person {
public:
    Car car;
};
int main()
{
    Student student;
    student.run();

    Person person;
    //汇编可以看到call了构造函数
    return 0;
}
