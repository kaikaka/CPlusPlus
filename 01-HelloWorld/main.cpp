#include <iostream>

using namespace std;




void dispaly() {

}

 void dispaly(int a) {
    cout << a << endl;
}

 void dispaly(double a) {
    cout << a << endl;
}

int main()
{
    cout << "Hello World!" << endl;

    dispaly();
    dispaly(10);
    dispaly(20.0);

    return 0;
}
