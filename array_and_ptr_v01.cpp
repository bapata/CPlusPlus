#include <iostream>
using namespace std;
int main() {

  int a[6]; // 6 'int' slots allocated, but contents are garbage
  int *p; // no memory allocated, can't access any contents

  // doesn't cause any segmentation fault, contents are unpredictable
  cout << a << endl;
  cout << a[5] << endl;

  // print where its pointing to (no where, garbage location)
  cout << p << endl;
  // cout << p[5] << endl;  // causes segmentation fault because no memory allocated
}
