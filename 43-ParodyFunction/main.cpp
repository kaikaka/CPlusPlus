#include <iostream>

using namespace std;

class Sum {
public:
    int m_age;
    int operator() (int a,int b) {
        if (m_age) {

        }
        return a + b;
    }
    void func() {
        m_age = 10;
    }
};

int main()
{
    Sum sum;
    sum.m_age = 11;
    sum.func();
    cout << sum.m_age << endl;

    cout << sum(10,20) << endl;

    cout << sum.operator()(10,20) << endl;

    return 0;
}
