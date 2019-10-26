#include <iostream>
using namespace std;

void func1(int somevar) {
  somevar=10;
}

void func2(int &somevar) {
  somevar=10;
}

void func3(int *somevar) {
  *somevar = 10;
}

int main() {
  int a = 0;
  func1(a);
  cout << "Did a change " << a << " " <<endl;
  func2(a);
  cout << "Did a change " << a << " " <<endl;
  func3(&a);
  cout << "Did a change " << a << " " <<endl;
  return 0;
}
