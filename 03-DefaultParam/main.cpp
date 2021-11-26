#include <iostream>

using namespace std;

int sum(int v1, int v2 = 20) {
    return v1 + v2;
}

void test(int a) {
    cout << "test(int) - " << a << endl;
}

void func (int v1, void(*p)(int) = test) {
    p(v1);
}

int main()
{
    int s1 = sum(1);
    int s2 = sum(10,30);
    cout << s1 << endl;
    cout << s2 << endl;

    func(10);
    void(*p)(int) = test;
    p(29);
    return 0;
}
