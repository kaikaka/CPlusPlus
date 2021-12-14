#include <iostream>

using namespace std;

class Person {
public:
    Person() {
        cout << "Person::Person()" << endl;
    }
    ~Person() {
        cout << "Person::~Person()" << endl;
    }
};

class Student: public Person {
public:
    Student() {
        cout << "Student::Student()" << endl;
    }
    ~Student() {
        cout << "Student::~Student()" << endl;
    }
};

int main()
{

    {
        Student student;
    }


    return 0;
}
