#include <iostream>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

int main()
{
//    const int age = 20;
//    age = 10;
//    const Date d = {2021,12,5};
//    d.day = 20;
//    Date d2 = {2020,12,5};
//    d = d2;
//    d.year = 2015;

//    Date d1 = {2011,2,5};
//    Date d2 = {2013,4,8};

//    const Date *p = &d1;
//    p->year = 2015;
//    (*p).month = 5;
//    *p = p2;

//    cout << d1.year << endl;
    int age = 10;
    int height = 30;

    const int *p1 = &age;

//    *p1 = 20;
    int const *p2 = &age;
//    p2 = 10;
//    *p2 = 20
    int * const p3 = &age;
//    p3 = 20;
    *p3 = 20;
    const int * const p4 = &age;
//    p4 = 1;
//    *p4 = 2;
//    p4 = &height;
    int const * const p5 = &age;
    //const 修饰的是右边的值
    return 0;
}
