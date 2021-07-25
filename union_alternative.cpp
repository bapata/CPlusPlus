#include <iostream>
#include <variant>
#include <string>

// demo code for variant usage. variant is a union alternative

using namespace std;

struct Entry {
  variant<char,int,double,bool,string> myid;
};


int main(void) {
  Entry myentry;

  myentry.myid=42;
  cout << get<int>(myentry.myid) << endl;

  myentry.myid=string("test string1");
  cout << get<string>(myentry.myid) << endl;
  myentry.myid="test string2";
  cout << get<string>(myentry.myid) << endl;


  myentry.myid=3.14159;
  cout << get<double>(myentry.myid) << endl;
}
