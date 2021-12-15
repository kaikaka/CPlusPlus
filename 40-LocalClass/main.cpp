#include <iostream>

using namespace std;

//局部类

int g_age = 10;

void test() {
    static int age = 10;
    class Car {
    public:
        void run() {
            age = 20;
        }
    };
    Car car;
    car.run();
    cout << age << endl;
    cout << g_age << endl;
}

int main()
{
    test();

    return 0;
}
