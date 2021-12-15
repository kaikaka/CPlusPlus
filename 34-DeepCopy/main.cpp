#include <iostream>

//浅拷贝(shallow copy)：指针类型的变量只会拷贝地址值
//深拷贝(deep copy)：将指针指向的内容拷贝到新的存储空间

using namespace std;


class Car {
    int m_price;
    char *m_name;
    void copy(const char *name = NULL) {
        if (name == NULL) return;
        m_name = new char[strlen(name) + 1] {};
        strcpy(m_name,name);
    }
public:
    Car(int price = 0,const char *name = NULL) :m_price(price){
        cout << "Car(int price = 0,const char *name = NULL)" << endl;
        copy(name);
    }
    Car(const Car &car):m_price(car.m_price) {
        cout << "Car(const Car &car)" << endl;
        copy(car.m_name);
    }
    ~Car() {
        if (m_name == NULL) return;
        delete[] m_name;
        m_name = NULL;
        cout << "~Car()" << this << endl;
    }
    void dispaly() {
        cout << "price is " << m_price << " name is " << m_name << endl;
    }
};

int main()
{
    Car car1(100,"bmw");
    Car car2 = car1;
    car2.dispaly();

    Car *car3 = new Car (200,"link");
     car3->dispaly();
     delete  car3;

    return 0;
}
