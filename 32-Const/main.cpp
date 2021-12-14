#include <iostream>

using namespace std;

class Car {
public:
    const int m_price;
    Car():m_price(0) {}
    void run() const {
        cout << "run()" << endl;
    }
};

int main()
{
    Car car;
    car.run();

    const Car car2;
    car2.run();
    //const 修饰的类只能调用const方法

    return 0;
}
