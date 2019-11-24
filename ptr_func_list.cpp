// Walk list of function to demonstrate how to use pointers to function
#include <iostream>
using namespace std;

int f1(string a) {
  cout << "In Function f1 " << "value of parameter is: " << a <<endl;
  return 0;
}
int f2(string a) {
  cout << "In Function f2 " << "value of parameter is: " << a <<endl;
  return 0;
}
int f3(string a) {
  cout << "In Function f3 " << "value of parameter is: " << a <<endl;
  return 0;
}
int f4(string a) {
  cout << "In Function f4 " << "value of parameter is: " << a <<endl;
  return 0;
}

typedef int (*F)(string a);
int main() {
  F f_list[] = { f1, f2 , f3, f4};
  int count = sizeof(f_list)/sizeof(f_list[0]);
  for (int ii=0;ii<count;ii++) {
    f_list[ii]("hello");
  }
}
