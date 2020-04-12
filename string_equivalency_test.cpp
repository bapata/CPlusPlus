#include <iostream>
using namespace std;

// Compare 2 strings. Delete char when you encounter '#'
// 'a#b#' and 'ab##' are equivalent
// 'bac#' and 'bab#' are equivalent

// Just for fun - my own stack class.
template <class Myitem>
class Mystack {
  private:
    Myitem mylist[25];
    int top_index;
  public:
    Mystack() { top_index=0; }

    void push(Myitem x) { mylist[top_index++]=x;}

    Myitem pop(void) { return mylist[top_index--];}

    void print_contents(void) {
      for(int ii=top_index-1;ii>=0;ii--) {
        cout << "Index: " << ii << " Value: " << mylist[ii] << endl;
      }
    }
    int getStackLen(void) { return top_index; }
};

int main(int argc,char **argv) {
  // test these equivalent string
  //string ts1="a#b#c";
  //string ts2="ab##";

  if(argc!=3) {
    cout << "USAGE: " << argv[0] << " <string1> <string2> " <<endl;
    exit(0);
  }
  string ts1=argv[1];
  string ts2=argv[2];

  Mystack<char> ms1,ms2;

  //ms.print_contents();
  int ii=0,jj=0;
  int ts1_len=ts1.length();
  int ts2_len=ts2.length();

  while(ii<ts1_len) {
    if (ts1[ii]!='#') {
      ms1.push(ts1[ii]);
    } else {
      ms1.pop();
    }
    ii++;
  }
  while(jj<ts2_len) {
    if (ts2[jj]!='#') {
      ms2.push(ts2[jj]);
    } else {
      ms2.pop();
    }
    jj++;
  }

  if(ms1.getStackLen() == ms2.getStackLen()) {
    cout << "Both strings are equivalent" << endl;
  } else {
    cout << "Both strings are NOT equivalent" << endl;
  }
  return 1;
}
