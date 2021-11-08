#include <iostream>
#include <string>
using namespace std;

class Version {
  private:
    string version_str;
    int version_cmp_(string v1,string v2) {
      return -1;
    }
  public:
  Version(string v) { version_str = v; }

  bool operator <(const Version& v) {
         if(version_cmp_(version_str,v.version_str) < 0) {
            return true;
         }
         return false;
  }
  bool operator >(const Version& v) {
         if(version_cmp_(version_str,v.version_str) > 0) {
            return true;
         }
         return false;
  }
  bool operator ==(const Version& v) {
         if(version_cmp_(version_str,v.version_str) == 0) {
            return true;
         }
         return false;
  }
  friend ostream& operator<<(ostream& os, const Version& v) {
    os << v.version_str;
    return os;
  }
};


void print_usage() {
  cout << "Example USAGE: ./this_script 1.2.32 1.3.30" << endl;
}

int main(int argc,char **argv) {
  if (argc!=3) {
    print_usage();
    exit(-1);
  }

  Version v1(argv[1]);
  Version v2(argv[2]);

  if (v1<v2) {
    cout << v1 << " is less than " << v2 << endl;
  } else if (v1>v2) {
    cout << v1 << " is greater than " << v2 << endl;
  } else {
    cout << v1 << " is equal to " << v2 << endl;
  }
}
