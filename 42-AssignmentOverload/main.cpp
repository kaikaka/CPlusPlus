#include <iostream>

using namespace std;

class Person {
public:
    int m_age;
    Person &operator=(const Person &person) {
        m_age = person.m_age;
        return *this;
    }
};

class Student : public Person {
public:
    int m_score;
    Student &operator= (const Student &student) {
        Person::operator=(student);
        m_score = student.m_score;
        return *this;
    }
};

int main()
{
        Student stu1;
        stu1.m_age = 20;
        stu1.m_score = 100;

        Student stu2;

        stu2 = stu1;

        cout << stu2.m_age << endl;
        cout << stu2.m_score << endl;

    return 0;
}
