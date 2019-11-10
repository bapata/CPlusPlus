#include <iostream>
using namespace std;

// members in structure are public by default
//typedef struct tagPoint {
//  int x;
//  int y;
//  tagPoint *next_point;
//} Point ;
typedef struct tagPoint {
  int x;
  int y;
  tagPoint *next_point;
} Point ;

Point *generate_point(int x_val,int y_val) {
  Point *tmp_point;
  tmp_point = new Point;
  tmp_point->x = x_val;
  tmp_point->y = y_val;
  tmp_point->next_point = NULL;
  return tmp_point;
}
int main() {
  // construct linked list of points
  Point *point_list;

  point_list = generate_point(0,0);
  point_list->next_point = generate_point(1,1);
  point_list->next_point->next_point = generate_point(2,2);

  // traverse linkedlist and print points
  while(point_list) {
    cout << "x = " << point_list->x << " y= " << point_list->y << endl;
    point_list = point_list->next_point;
  }
  return 0;
}
