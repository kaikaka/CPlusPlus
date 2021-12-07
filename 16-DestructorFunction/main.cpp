#include <iostream>

using namespace std;

class Person {
public:
    Person() {
        cout << "Person::Person()" << endl;
    }
    ~Person() {
        cout << "~Person()" << endl;
    }
};

void test() {
    Person person;
}

int main()
{
    test();
    Person *p = new Person ();
    cout << p << endl;
    cout << &p << endl;

    delete  p;

    return 0;
}
