#include <iostream>

using namespace std;
class Sample {
  private:
    int a;
  public:
    Sample() { }
    ~Sample() { }
    // If you don't use 'this', the function will assign value to its parameter
    void f(int &a) { this->a=a; }
    void print_a(void) { cout << "A is " << a <<endl; }
};

int main() {
  Sample s1;
  int a = 10;
  s1.f(a);
  s1.print_a();
  return 0;
}
