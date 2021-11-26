#include <iostream>

using namespace std;

void display() {
  cout << "display()" << endl;
}

void display(int a) {
  cout << "display(Int)" << endl;
}

void display(long a) {
  cout << "display(long)" << endl;
}

void display(double a) {
  cout << "display(double)" << endl;
}

int main()
{
   display();
   display(10);
   display(10L);
   display(10.0);

    return 0;
}
