#include <iostream>

// print arguments and program name in reverse order
using namespace std;

int main(int argc,char **argv) {
  if (argc<=0) {
    return 0;
  } else {
    cout << argv[--argc] << endl;
    main(argc,argv);
  }
}
