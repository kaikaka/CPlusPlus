#include <iostream>

using namespace std;

class Person {
public:
    int age;
    void run() {
        cout << "Person::run()" << endl;
    }
};

void test() {
    //利用类创建对象
    Person person;
    person.age = 20;
    person.run();

    Person *p = &person;
    p->age = 40;
    p->run();

    Person person1;
    person1.run();//call 函数地址

    Person person2;
    person2.run();//call 函数地址

    Person person3;
    person3.run();//call 函数地址

}

int main()
{
    test();
    return 0;
}
