#include <iostream>

using namespace std;
//类/对象/返回值
class Car {
public:
    Car() {
        cout << "Car()-" << this << endl;
    }

    Car(const Car &car) {
        cout << "Car(const Car &car)" << this << endl;
    }

    ~Car() {
        cout << "~Car()-" << this << endl;
    }
    void run() {
        cout << "run()" << endl;
    }
};

void test1(Car car) {

}

Car test2() {
    return Car();
}

int main()
{
    cout << "------1-----" << endl;
    Car car1;
    cout << "------1-----" << endl;
    car1 = test2();
    cout << "------2-----" << endl;
    test1(Car());
    cout << "------2-----" << endl;

    Car().run();
    cout << "------3-----" << endl;
    return 0;
}
