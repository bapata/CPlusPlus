#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

// kaprekar constant 6174

using namespace std;

int high_to_low(int n) {
  char tmp[256];
  sprintf(tmp,"%d",n);
  string n_as_str(tmp);
  sort(n_as_str.begin(), n_as_str.end());
  reverse(n_as_str.begin(), n_as_str.end());
  return atoi(n_as_str.c_str());
}

int low_to_high(int n) {
  char tmp[256];
  sprintf(tmp,"%d",n);
  string n_as_str(tmp);
  sort(n_as_str.begin(), n_as_str.end());
  return atoi(n_as_str.c_str());
}

int main(int argc,char **argv) {
  if(argc!=2) {
    return 1;
  }
  int n = atoi(argv[1]);
  if ( (n<1000) || (n>9999) ) {
    cout << "Digit has to be between 1000 and 9999 .." << endl;
    exit(1);
  }
  int knum_constant = 6174;
  cout<<"You started with initial number = " << n << endl;
  int a=0,b=0;

  while (n != knum_constant) {
    a=high_to_low(n);
    cout << "high_to_low: " << a << endl;
    b=low_to_high(n);
    cout << "low_to_high: " << b << endl;
    n=a-b;
    if(n<=0) {
      cout << "digits should be unique, please try again" << endl;
      exit(1);
    }
    cout << "intermediate number is: " << n << endl;
  }
  cout << "We have hit kaprekars number: " << n << endl;
}
