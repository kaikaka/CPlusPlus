#include <iostream>

using namespace std;

class Person {

};

class Student: public Person {
public:
    int m_no;
};

class GoodStudent: public Student {
public:
    int m_money;
};

int main()
{
    cout << sizeof (GoodStudent) << endl;

    GoodStudent gs;
    gs.m_no = 9;
    gs.m_money = 8;

    GoodStudent gs1;
    gs1.m_no = 2;

    cout << sizeof (gs) << endl;
    cout << sizeof (gs1) << endl;

    return 0;
}
