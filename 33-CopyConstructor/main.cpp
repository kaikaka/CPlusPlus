#include <iostream>

using namespace std;
//copy 构造
class Car {
public:
    int m_price;
    int m_length;
    Car (int price = 0,int length = 0) :m_price(price),m_length(length) {
        cout << "Car(int price = 0,int length = 0)" << endl;
    }
//    Car(const Car &car):m_price(car.m_price) {
//        cout << "Car(const Car &car)" << endl;
//    }
    Car(const Car &car):m_price(car.m_price),m_length(car.m_length) {
        cout << "Car(const Car &car)" << endl;
    }
    void display() {
        cout << "price = " << m_price << " length = " << m_length << endl;
    }
};

void test() {
    cout << "-----------test------------" << endl;
    Car car1(100,5);
    Car car2(car1);
    Car car3 = car2;
    Car car4;
    car4.display();

//    *car4 = car3;//gcc中无法这样赋值
    cout << "-----------test------------" << endl;
}

void test1() {
    cout << "----------test1-------------" << endl;
    Car car1(100,5);
    Car car2(car1);
    car2.m_price = 200;
    car2.m_length = car1.m_length;
    car2.display();
    cout << "----------test1-------------" << endl;
}

int main()
{
    test();
    test1();
    return 0;
}
