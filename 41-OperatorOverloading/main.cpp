#include <iostream>
//运算符重载
using namespace std;

class Point {
    friend ostream &operator<<(ostream & , const Point &);
    friend istream &operator>>(istream &,Point &);
        int m_x;
        int m_y;
    public:
        Point(int x, int y) :m_x(x), m_y(y) {}
        void display() {
            cout << "(" << m_x << ", " << m_y << ")" << endl;
        }
        Point(const Point &point) {
            m_x = point.m_x;
            m_y = point.m_y;
        }
        //后置++
        const Point operator++(int) {
            Point old1(m_x,m_y);
            m_x ++;
            m_y ++;
            return old1;
        }
        //前置++
        Point &operator++() {
            m_x++;
            m_y++;
            return *this;
        }

        const Point operator+(const Point &point) const {
            cout << "operator+" << endl;
            return Point(m_x + point.m_x,m_y + point.m_y);
        }

        const Point operator-(const Point &point) const {
            return Point(m_x - point.m_x,m_y - point.m_y);;
        }
        Point &operator+=(const Point &point) {
            m_x += point.m_x;
            m_y += point.m_y;
            return *this;
        }

        bool operator==(const Point &point) const {
            return (m_x == point.m_x) && (m_y == point.m_y);
        }

        bool operator!=(const Point &point) const {
            return (m_x != point.m_x) || (m_y != point.m_y);
        }
        const Point operator-() const {
            return Point(-m_x,-m_y);
        }
};

//<<重载
ostream &operator<<(ostream &cout , const Point &point) {
    cout << "(" << point.m_x << "," << point.m_y << ")" << endl;
    return cout;
}
//>>
istream &operator>>(istream &cin,Point &point) {
   cin >> point.m_x;
   cin >> point.m_y;
   return cin;
}

int main()
{
    cout << "----------------1----------------" << endl;
    Point p1 = Point(10,20);
    Point p2 = p1++;
    p2.display();
    cout << p2 << endl;
    cout << "----------------1----------------" << endl;
    Point p3 = Point(10,20);
    Point p4 = ++p3;
    cout << p4 << endl;
    cout << "----------------2----------------" << endl;
    Point p5 = Point(100,200) + Point(11,11);
    cout << p5 << endl;
    cout << "----------------3----------------" << endl;
    Point p6 = Point(100,200) - Point(11,11);
    cout << p6 << endl;
    cout << "----------------4----------------" << endl;
    Point p7 = Point(10,20);
    p7 += p6;
    cout << p7 << endl;
    cout << "----------------5----------------" << endl;
    cout << (Point(99,209) == p7) << endl;
    cout << "----------------6----------------" << endl;
    cout << (Point(99,209) != p7) << endl;
    cout << "----------------7----------------" << endl;
    cout << -Point(99,209) << endl;
    cout << "----------------8----------------" << endl;
    return 0;
}
