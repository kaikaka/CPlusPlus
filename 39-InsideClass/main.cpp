#include <iostream>

using namespace std;

//内部类
class Person {
private:
    int m_age;
public:
    class Car {
    private:
        int m_price;
    };
};

int main()
{
    Person::Car car1;
    return 0;
}
