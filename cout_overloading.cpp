#include <iostream>

using namespace std;

typedef struct Node {
  int x;
  short y;
};

ostream& operator <<(ostream& output, const Node& data)
{
    output << "X is : " << data.x << " Y is: " << data.y << endl;
    return output;
}


int main() {
  Node n1 = { 1,2 };
  cout << n1 << endl;
}
