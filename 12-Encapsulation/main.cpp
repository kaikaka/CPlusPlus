#include <iostream>

using namespace std;
//封装

class Person {
private:
    int m_age;
public:
    void setAge(int age) {
       if (age <= 0) {
           m_age = 1;
       } else {
           m_age = age;
       }
    }
    int getAge() {
        return m_age;
    }
};

int main()
{
    Person person;
    person.setAge(-5);


    cout << person.getAge() << endl;
//    person.m_age = 0;
    return 0;
}
