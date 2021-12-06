#include <iostream>

using namespace std;

void test() {
    int age = 10;
    int height = 20;

    //&ref 别名
    int &ref = age;
    int &ref1 = ref;
    int &ref2 = ref1;
    ref += 10;
    ref1 += 10;
    ref2 += 10;
    cout << age << endl;
}

void swap(int &v1,int &v2) {
    int tmp = v1;
    v1 = v2;
    v2 = tmp;
}

int test2() {
    int a = 10;
    int b = 20;
    swap(a,b);
    cout << "a = " << a <<",b = " << b << endl;
}

struct Student {
    int &age;//引用相当于指针
};

int main()
{
    test();
    test2();
    cout << sizeof (Student) << endl;
    return 0;
}
