#include <iostream>
#include "Array.hpp"

using namespace std;

class Point {
    friend ostream &operator<<(ostream &, const Point &);
    int m_x;
    int m_y;
public:
    Point(int x = 0, int y = 0) :m_x(x), m_y(y) {}
};

ostream &operator<<(ostream &cout, const Point &point) {
    return cout << "(" << point.m_x << ", " << point.m_y << ")";
}

class Person {

};

class Car {

};
//类模板
int main()
{
    Array<int> array;
        array.add(10);
        array.add(20);
        array.add(30);

        cout << array.size() << endl;
        // 3

        Array<void *> array1;
        array1.add(new Point(3, 4));
        array1.add(new Car());

        cout << array1.size() << endl;//2

    return 0;
}
