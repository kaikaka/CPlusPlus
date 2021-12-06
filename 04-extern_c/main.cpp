#include <iostream>

using namespace std;

extern "C" {
    void func() {
        printf("func");
    }
}

int main()
{
    func();
    return 0;
}
