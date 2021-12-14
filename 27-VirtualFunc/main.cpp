#include <iostream>

using namespace std;
//oc的协议/java的抽象类、接口
//Animal 纯虚函数
//如果父类是抽象类，子类没有完全重写纯虚函数，那么这个子类依然是抽象类
class Animal {
public:
    virtual void speak() = 0;
    virtual void run() = 0;
};

class Dog:public Animal {
public:
    void run() {
        cout << "Dog::run()" << endl;
    }
};


class littleDog:public Dog {
public:
    void speak() {
        cout << "Little::speak" << endl;
    }
};

int main()
{
//    Animal *dog = new Dog ();
    Animal *lDog = new littleDog ();
    lDog->speak();
    lDog->run();

    return 0;
}
