#include <iostream>

// Implemntation for https://en.wikipedia.org/wiki/Collatz_conjecture
// In this algo, we stop when number reaches value of 1

using namespace std;

void collatz(int n ) {
  cout << "Starting with " << n << endl;
  while (n>1) {
    if (n%2==0) {
      n = n/2;
      cout << "EVEN, so n/2 = " << n << endl;
    } else {
      n = 3*n+1;
      cout << "ODD, so 3n+1 = " << n << endl;
    }
  }
}

//## Usage <script> <integer>
int main(int argc,char **argv) {
  if(argc<=1) {
    cout << "\nUSAGE: <script> <number>\n" <<endl;
    exit(1);
  }
  int num = atoi(argv[1]);
  collatz(num);
}
