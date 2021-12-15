#include <iostream>

using namespace std;

template <typename T>
class SmartPointer {
private:
    T *m_obj;
public:
    SmartPointer(T *obj) :m_obj(obj) {

    }
    ~SmartPointer() {
        if (m_obj == nullptr) return;
        delete m_obj;
    }

    T *operator->() {
        return m_obj;
    }
};


class Person {
    int m_age;
public:
    Person() {
        cout << "Person()" << endl;
    }
    Person(int age) :m_age(age) {
        cout << "Person(int)" << endl;
    }
    ~Person() {
        cout << "~Person()" << endl;
    }
    void run() {
        cout << "run() - " << m_age << endl;
    }
};

void test() {
    Person *p = new Person (20);
    p->run();
    cout << "-------1--------" << endl;
    {
        SmartPointer<Person> p(new Person(20));
        p->run();
    }
    cout << "-------2--------" << endl;
}

void test2() {
    //多个shared_ptr可以指向同一个对象，当最后一个shared_ptr在作用域范围内结束时，对象才会被自动释放
    shared_ptr<Person>p4;
    {
        shared_ptr<Person> p1(new Person(10));
        cout << p1.use_count() << endl;//1 p1

        shared_ptr<Person> p3;
        {
            shared_ptr<Person> p2 = p1;
            cout << p2.use_count() << endl;//2 p1 p2
            p3 = p2;
        }
        cout << p3.use_count() << endl;//2 p1 p3
        p4 = p3;
        cout << p4.use_count() << endl;//3 p1 p3 p4
    }
    cout << p4.use_count() << endl;//1 p4
}

class Person1;

class Car {
public:
    //weak_ptr可以指向对象解决shared_ptr的循环引用问题
weak_ptr<Person1> m_person;
Car() {
    cout << "Car()" << endl;
}
~Car() {
    cout << "~Car()" << endl;
}
};

class Person1 {
public:
    shared_ptr<Car> m_car;
    Person1() {
            cout << "Person()" << endl;
        }
        ~Person1() {
            cout << "~Person()" << endl;
        }
};

void test3() {
    shared_ptr<Person1> person1(new Person1());
    shared_ptr<Car> car(new Car());
    person1->m_car = car;
    car->m_person = person1;
    //循环引用问题
}

int main()
{
    test();
    test2();
    test3();
    cout << "unique_ptr" << endl;
    //unique_ptr也会对一个对象产生强引用，它可以确保同一时间只有1个指针指向对象
//    ◼ 当unique_ptr销毁时(作用域结束时)，其指向的对象也就自动销毁了
//    ◼ 可以使用std::move函数转移unique_ptr的所有权
    unique_ptr <Person1> p0;
    {
        unique_ptr<Person1> p1(new Person1());
        p0 = std::move(p1);
    }
    return 0;
}
