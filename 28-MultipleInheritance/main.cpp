#include <iostream>

using namespace std;

struct Student {
    int m_score;
    Student(int score) :m_score(score) {}
    void study() {
        cout << "Student::study() - score = " << m_score << endl;
    }
};

struct Worker {
    int m_salary;
    Worker(int salary) :m_salary(salary) {}
    void work() {
        cout << "Worker::work() - salary = " << m_salary << endl;
    }
};

struct Undergraduate : Student, Worker {
    int m_grade;
    Undergraduate(int score, int salary, int grade)
        :Student(score),
        m_grade(grade),
        Worker(salary) {}
    void play() {
        cout << "Undergraduate::play() - grade = " << m_grade << endl;
    }
};

int main()
{
        Undergraduate ug(100,200,300);
        ug.m_score = 100;
        ug.m_salary = 2000;
        ug.m_grade = 4;
        ug.study();
        ug.work();
        ug.play();
    //Worker w = {.m_salary = 12};
    //cout << "w = " << w.m_salary << endl;


    return 0;
}
