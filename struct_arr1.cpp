#include <iostream>
using namespace std;

// members in structure are public by default
typedef struct {
  int x;
  int y;
} Point ;

int main() {
  Point p[] = { {0,0},{1,1},{2,2} };

  int number_of_points = sizeof(p)/sizeof(p[0]);
  for (int ii=0;ii<number_of_points;ii++) {
    cout << "x = " << p[ii].x << ", y= " << p[ii].y << endl;
  }
}
