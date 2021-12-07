#include <iostream>

using namespace std;

namespace KK {
    void func () {
        cout << "KK::func" << endl;
    }
}

int main()
{
    using namespace KK;
    KK::func();
    return 0;
}
