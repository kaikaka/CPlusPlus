#include <iostream>

using namespace std;

/*
 什么时候使用内联函数？
 1.函数代码体积不大
 2.频繁调用的函数
*/

inline void func() {

}

inline int sum(int v1,int v2) {
    return v1 + v2;
}

//内联函数不可以是递归
//inline void run() {
//    run();
//}

void test() {
//    run();
    func();
    int c = sum(10,20);
    cout << c << endl;
}

inline int add(int v) {
    return v + v;
}

int main()
{
//    test();
    int a = 10;
    int c = add(++a);

    cout << c << endl;
    return 0;
}
