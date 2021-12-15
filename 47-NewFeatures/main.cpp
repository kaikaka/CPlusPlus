#include <iostream>

using namespace std;

int age = 10;
auto test() {
    int a = 10;
    return [] {
        cout << "func() ------" << age << endl;
    };
}

void test1() {
    cout << "test1" << endl;
    //值捕获
    int a = 10;
    int b = 20;
    auto func = [a,b] {
        cout << a << endl;
        cout << b << endl;
    };
    a = 11;
    b = 22;
    func();
}

void test2 () {
    cout << "test2" << endl;
    //隐式捕获(值捕获)
    int a = 10;
    int b = 20;
    auto func = [=] {
        cout << a << endl;
        cout << b << endl;
    };
    a = 11;
    b = 22;
    func();
}

void test3() {
    cout << "test3" << endl;
    int a = 10;
    int b = 20;
    auto func = [&,a] {
        cout << a << endl;
        cout << b << endl;
    };
    a = 11;
    b = 22;
    func();
    //a是值捕获，其他是地址捕获
}

void test4() {
    cout << "test4" << endl;
    int a = 10;
    int b = 20;
    auto func = [&a,b] {
        cout << a << endl;
        cout << b << endl;
    };
    a = 11;
    b = 22;
    func();
    //a是地址捕获，其他是值捕获
}

void test5() {
    cout << "test5" << endl;
    int a = 10;
    int b = 20;
    auto func = [&] {
        cout << a << endl;
        cout << b << endl;
    };
    a = 11;
    b = 22;
    func();
    //隐式地址捕获
}

void test6() {
    cout << "test6" << endl;
    int a = 10;
    int b = 20;
    auto func = [=,&a] {
        cout << a << endl;
        cout << b << endl;
    };
    a = 11;
    b = 22;
    func();
    //a是地址捕获，其余变量是值捕获
}

int add(int v1, int v2) {
    return v1 + v2;
}

int sub(int v1, int v2) {
    return v1 - v2;
}

int multiple(int v1, int v2) {
    return v1 * v2;
}

int divide(int v1, int v2) {
    return v1 / v2;
}

int exec(int v1, int v2, int (*func)(int, int)) {
    return func(v1, v2);
}

int main()
{
    auto p = test();
    p();
    cout << "-----1------" << endl;
    int a = 10;
    auto func = [&a] {
        a++;
    };
    func();
    cout << a << endl;
    cout << "----2-------" << endl;

    auto func2 = [a]() mutable {
        a++;
        cout << "lambda = " << a << endl;
    };
    func2();
    cout << "-----3------" << endl;
    cout << a << endl;
    cout << "-----4------" << endl;
    // 默认都是值捕获
    auto func3 = [a] {
           cout << a << endl;
    };
    func3();
    cout << "-----5------" << endl;
    // 地址捕获
    auto func4 = [&a] {
        cout << a << endl;
    };
    func4();
    cout << "-----6------" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    cout << "-----7------" << endl;

    cout << exec(20, 10, [] (int v1, int v2) { return v1 + v2; }) << endl;
    cout << exec(20, 10, [] (int v1, int v2) { return v1 - v2; }) << endl;
    cout << exec(20, 10, [] (int v1, int v2) { return v1 * v2; }) << endl;
    cout << exec(20, 10, [] (int v1, int v2) { return v1 / v2; }) << endl;

    return 0;
}
