#include <iostream>
#include "Person.h"

using namespace std;

//类的声明与实现分离

int main()
{
    Person person;
    person.setAge(10);
    cout << person.getAge() << endl;
    return 0;
}
