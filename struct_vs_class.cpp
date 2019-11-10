#include <iostream>
#include <math.h>
using namespace std;

// members in structure are public by default
struct Point {
  int x;
  int y;
  float distance_formula(void) { return sqrt(x*x+y*y); }
};

// members in structure are private by default
class CPoint {
  int x;
  int y;
  float distance_formula(void) { return sqrt(x*x+y*y); }
};

int main() {
  Point p1;
  p1.x = 10;
  cout << p1.distance_formula() << endl;

  CPoint cp1;
  // cp1.x = 10; // this will be a compilation error
  //cout << cp1.distance_formula() << endl;
}
