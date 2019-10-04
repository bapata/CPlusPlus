// compute factorial of numbers specified as command line arguments
// Save this file as fact_cli.cpp
// Compile using g++ fact_cli.cpp -o fact_cli
// Execution example:
// ./fact_cli 4 2 5 6
//  Factorial of 4 is 24
//  Factorial of 2 is 2
//  Factorial of 5 is 120
//  Factorial of 6 is 720
//
// ./fact_cli 3 7
// Factorial of 3 is 6
// Factorial of 7 is 5040

// ./fact_cli
// Atleast one argument is required. USAGE: <this-program> <arg1> [ arg2 arg3 ... ]

// ./fact_cli 8
// Factorial of 8 is 40320

#include <iostream>
#include <stdlib.h>

using namespace std;

int fact(int n) {
  if (n<=0) {
    return 1;
  }
  return n*fact(n-1);
}


// USAGE: <this-program> <arg1> [ arg2 arg3 ... ]
// Atleast one argument is required

int main(int argc,char **argv) {
  // argv[0] is this program name
  // argv[1..N-1] are arguments


  int n_as_int;
  if (argc<2) {
    cout << "\nAtleast one argument is required. USAGE: <this-program> <arg1> [ arg2 arg3 ... ]\n";
    exit(1);
  }

  for (int ii=1;ii<argc;ii++) {
    n_as_int = atoi(argv[ii]);
    cout << "Factorial of " << n_as_int << " is " << fact(n_as_int) << " " << endl;
  }
  exit(0);
}
