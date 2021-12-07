#include <iostream>

using namespace std;

class Person {
    public:
    int m_age;

    protected:
    void setAge(int age) {
        m_age = age;
    }

    int getAge() {
        return m_age;
    }
};

class Student : protected Person {
public:
    void run() {
        cout << m_age << endl;
    }
};

class GoodStudent : public Student {
    void work() {

    }
};

int main()
{
    Student *pp = new Student();
   pp->run();
    delete pp;
    return 0;
}
