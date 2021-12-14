#include <iostream>

using namespace std;

//多态原理 虚表

class Animal {
public:
    void speak() {
        cout << "Animal::speak()" << endl;
    }
    void run() {
        cout << "Animal::run()" << endl;
    }

    Animal() {
        cout << "Animal::Animal()" << endl;
    }

    virtual ~Animal() {
        cout << "Animal::~Animal()" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() {
        cout << "Cat::speak()" << endl;
    }
    void run() {
        cout << "Cat::run()" << endl;
    }

    Cat() {
        cout << "Cat::Cat()" << endl;
    }

    ~Cat() {
        cout << "Cat::~Cat()" << endl;
    }
};

class WhiteCat: public Cat {
public:
    void speak() {
        cout << "WhiteCat::speak()" << endl;
    }
    void run() {
        cout << "WhiteCat::run()" << endl;
    }
};

class WhiteWhiteCat: public WhiteCat {
public:
    void speak() {
        cout << "WhiteWhiteCat::speak()" << endl;
    }
    void run() {
        cout << "WhiteWhiteCat::run()" << endl;
    }
};

int main()
{
    Animal *cat0 = new Cat ();
    delete cat0;

    cout << "------------------" << endl;
    Animal *cat1 = new WhiteCat ();
    cat1->speak();
    cat1->run();
    delete  cat1;
    cout << "------------------" << endl;

    WhiteCat *cat2 = new WhiteWhiteCat ();
    cat2->speak();
    cat2->run();
    delete cat2;
    cout << "------------------" << endl;

    Animal *anim = new Animal ();
    anim->speak();
    anim->run();
    delete  anim;
    return 0;
}
