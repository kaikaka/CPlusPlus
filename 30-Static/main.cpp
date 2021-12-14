
#include <iostream>

using namespace std;

class Car {
private:
    static int ms_count;
public:
    Car() {
        ms_count ++;
        cout << "Car::()" << endl;
    }
    ~Car() {
        ms_count --;
        cout << "~Car::() " << endl;
    }
    static int getCount() {
        return ms_count;
    }
};

int Car::ms_count = 12;

Car g_car;

int main()
{
    Car car;

    Car *p = new Car ();
    delete  p;

    cout << Car::getCount() << endl;

    return 0;
}
