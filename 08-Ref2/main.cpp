#include <iostream>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

void test() {
    int age = 10;
        int &ref = age;

//            Date d = {2011, 1, 5};

//            Date &ref = d;
//            ref.day = 2014;

    //        int age = 10;
    //        int *p = &age;
    //        int *&ref = p;
    //        *ref = 30;
    //        int height = 30;
    //        ref = &height;
//        int array[] = {1,2,3};
//        int (&ref)[3] = array;
        int *p;
        int *arr1[3] = {p,p,p};
        int (*arr2)[3];
}

void test1() {
    int height = 20;
    int age = 10;
//    int & const ref1 = age;
//    ref1 = 30;
    int const &ref2 = age;
//    ref2 = 40;

    int * const p1 = &age;
//    p1 = &height;
    *p1 = 30;

    int const *p2 = &age;
    p2 = &height;
//    *p2 = 30;
    const int &ref = age;
    const int *p = &age;
//    ref = 30;
//    *p = 30;
    cout << ref << endl;
    cout << *p << endl;
}

int func () {
    return 10;
}

int main()
{
    test1();

    int age = 10;
    const long &ref = age;
    age = 30;
    cout << ref << endl;

    int arr[] = {1,2,3};
    int (&ref1)[3] = arr;
    //数组的首地址
    int * const &ref2 = arr;

    int a = 1;
    int b = 2;
    const int &ref3 = 30;
    const int &ref4 = a + b;
    const int &ref5 = func();
//ref3 = 10;
//ref4 = 50;

    cout << ref2 << endl;
    cout << ref3 << endl;
    cout << ref4 << endl;
    cout << ref5 << endl;

    return 0;
}
