#include <iostream>

using namespace std;
//多态

class Animal {
public:
    virtual void speak() {
        cout << "Animal:: speak()" << endl;
    }
    virtual void run() {
        cout << "Animal:: run()" << endl;
    }
};

class Dog: public Animal {
public:
    void speak() {
        cout << "Dog:: speak()" << endl;
    }
    void run() {
        cout << "Dog:: run()" << endl;
    }
};

class Cat: public Animal {
public:
    void speak() {
        cout << "Cat:: speak()" << endl;
    }
    void run() {
        cout << "Cat:: run()" << endl;
    }
};

class Pig: public Animal {
public:
    void speak() {
        cout << "Pig:: speak()" << endl;
    }
    void run() {
        cout << "Pig:: run()" << endl;
    }
};

void liu(Animal *p) {
    p->speak();
    p->run();
}


int main()
{
//    Animal *p = new Dog ();
//    p->speak(); // 不加关键字virtual ，调用Animal:: speak()，否则调用Dog:: speak()
//    p->run();// 不加关键字virtual ，调用Animal:: run()，否则调用Dog:: run()

    liu(new Dog ());
    liu(new Cat ());
    liu(new Pig ());
    return 0;
}
