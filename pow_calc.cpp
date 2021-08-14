#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc,char **argv) {
  for (int ii=1;ii<argc;ii++) {
    double f = atof(argv[ii]);
    double val = pow(f,f);
    cout << f << "," << val << endl;
  }
}

// g++ pow_calc.cpp -o pow_calc
// ./pow_calc 0.1 0.01 0.001 0.0001 0.00001 0.0000001 0.00000001
// 0.1,0.794328
// 0.01,0.954993
// 0.001,0.993116
// 0.0001,0.999079
// 1e-05,0.999885
// 1e-07,0.999998
// 1e-08,1

