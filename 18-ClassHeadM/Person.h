#ifndef PERSON_H
#define PERSON_H

class Person {
private:
    int m_age;
public:
    void setAge(int age) ;
    int getAge() ;
    Person();
    ~Person();
};

#endif // PERSON_H
