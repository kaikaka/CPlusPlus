#include <iostream>

using namespace std;

//内存空间

//全局区
int g_age = 10;

void test() {
    int a = 1;
    int b = 2;
    int c = a + b;
    g_age = 1;
    cout << "a = " << &a << endl;
    cout << "b = " << &b << endl;
    cout << "c = " << &c << endl;
    cout << "g_age = " << &g_age << endl;
}

void test1() {
    int *p = (int *) malloc(4);
    *p = 9;
    cout << "*p = " << *p << endl;
    cout << "p = " << p << endl;
    cout << "&p = " << &p << endl;
    free(p);

    char *p1 = (char *) malloc(4);
    p1[0] = 1;
    p1[1] = 2;
    p1[2] = 3;
    p1[3] = 4;
    free(p1);
}

void test2() {
    char *p = new char[4];
    delete [] p;
}

void test3() {
    int size = sizeof(int) * 10;
    int *p = (int *)malloc(size);
    //清空
//    memset(p,0,size);
//    从p地址开始的连续4个字节中的每一个字节都设置为1
    memset(p, 1, 4);
    // 将4个字节设置为1
        // 00000000 00000000 00000000 00000001

        // 将4个字节中的每一个字节都设置为1
        // 00000001 00000001 00000001 00000001

    cout << "test 3 p = " << p << endl;
    cout << "test 3 *p = " << *p << endl;
    free(p);
}

void test4() {
    int *p0 = new int;
    int *p1 = new int();
    int *p2 = new int (5);
    cout << *p0 << endl;
    cout << *p1 << endl;
    cout << *p2 << endl;
    delete  p0;
    delete  p1;
    delete  p2;
}

int main()
{
    test();
    test1();
    test2();
    test3();
    test4();
    return 0;
}
