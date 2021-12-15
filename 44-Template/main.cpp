#include <iostream>
#import "add.h"

using namespace std;

class Point {
    friend ostream &operator<<(ostream &, const Point &);
    int m_x;
    int m_y;
public:
    Point(int x, int y) :m_x(x), m_y(y) {}
    Point operator+(const Point &point) {
        return Point(m_x + point.m_x, m_y + point.m_y);
    }
};

ostream &operator<<(ostream &cout, const Point &point) {
    return cout << "(" << point.m_x << ", " << point.m_y << ")";
}

int main()
{
    cout << add(10,20) << endl;
    cout << add(1.5,21.2) << endl;
    cout << add(Point(1,2),Point(3,4)) << endl;

    cout << toPlus(10,20) << endl;
    cout << toPlus(1.5,21.2) << endl;
    cout << toPlus(Point(1,2),Point(3,4)) << endl;

    return 0;
}
