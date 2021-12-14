#include <iostream>

using namespace std;
/*
单例模式：设计模式的一种，保证某个类永远只创建一个对象
1.构造函数\析构函数私有化
2.定义一个私有的static成员变量指向唯一的那个单例对象
3.提供一个公共的访问单例对象的接口
*/
class Rocket {
private:
    static Rocket *ms_rocket;
    Rocket() {}
    Rocket(const Rocket &rocket) {}
    ~Rocket() {}
    void operator=(const Rocket &rocket) {}
public:
    static Rocket *sharedRocket() {
        //这里要考虑多线程安全
        if (ms_rocket == NULL) {
            ms_rocket = new Rocket ();
        }
        return ms_rocket;
    }
    static void deleteRocket() {
        //这里也要考虑多线程安全
        if (ms_rocket != NULL) {
            delete  ms_rocket;
            ms_rocket = NULL;
        }
    }
};

Rocket *Rocket::ms_rocket = NULL;

int main()
{
    Rocket *p1 = Rocket::sharedRocket();
    Rocket *p2 = Rocket::sharedRocket();

    cout << p1 << endl;
    cout << p2 << endl;

    return 0;
}
