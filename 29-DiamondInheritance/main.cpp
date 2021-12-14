
#include <iostream>

using namespace std;

// 没有使用虚继承  （92）：10 * 2 + 3 = 23 * 4
// 使用虚继承：内存对齐 8， 10 * 4 + 8 + 8 + 16 = 72
struct Person {
public:
    int m_age = 1;
    int m_age1 = 1;
    int m_age2 = 1;
    int m_age3 = 1;
    int m_age4 = 1;
    int m_age5 = 1;
    int m_age6 = 1;
    int m_age7 = 1;
    int m_age8 = 1;
    int m_age9 = 1;
};

class Student : virtual Person {
    public:
    //0 8
    int m_score = 2; //1 16
//    int m_score1 = 21;//2 16
//    int m_score2 = 22; //3 24
//    int m_score3 = 23; //4 24
//    int m_score4 = 25; //5 32
};

class Worker : virtual Person {
    public:
    int m_salary = 3;
};

class Undergraduate :public Student, Worker {
    public:
    int m_grade = 4;
};

int main() {
    Undergraduate ug;
   // ug.m_age = 10;

    cout << sizeof(Undergraduate) << endl;
    cout << sizeof(Person) << endl;
    cout << sizeof(Student) << endl;
    cout << sizeof(Worker) << endl;
    return 0;
}
