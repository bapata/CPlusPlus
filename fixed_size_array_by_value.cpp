#include <iostream>
using namespace std;

// how to pass fixed size array by value?
// add fixed size array in a structure and pass structure by value

typedef struct { int a[6]; } node_t;

void print_ints(node_t n) {
  int count = sizeof(n)/sizeof(int);
  for(int ii=0;ii<count;ii++) {
    cout << n.a[ii] << endl;
  }
}
int main() {
  node_t mynode = { { 1,2,3,4,5,6} };
  print_ints(mynode);
}
