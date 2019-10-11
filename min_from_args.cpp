// Program to calculate min from command line arguments
// USAGE: ./min_from_args num1 num2 [num3 num4 ... ]
// Example: 
// ./min_from_args -2 10 -5 8
// -5

#include <iostream>
#include <stdlib.h>

using namespace std;
int main(int argc,char **argv) {
  char *prog_name = argv[0];
  int min=atoi(argv[1]);
  for (int ii=2;ii<argc;ii++) {
    int tmp = atoi(argv[ii]);
    if (tmp<min) {
      min = tmp;
    }
  }
  cout << "\nMin = " << min << endl;
  exit(0);
}
