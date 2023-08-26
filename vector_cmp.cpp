#include <vector>
#include <string>
#include <cassert>
#include <iostream>

using namespace std;

int main() {
  vector<int> data1{1,2,4,5};
  vector<int> data2{1,3,6,7};
  vector<int> data3{1,3};

  if (data1<data2) {
    cout << "data1 < data2" <<endl;
  }
}
