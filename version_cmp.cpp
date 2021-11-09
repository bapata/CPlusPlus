#include <iostream>
#include <string>
#include <regex>

// Compile as below
// g++ version_cmp.cpp --std=c++2a -o vercmp
// Run as below:
// ./vercmp 1.1.1 1.1.2

using namespace std;

class Version {
  private:
    string version_str;
    vector<int> string_to_int_arr_(string version_str) {
      regex regex("\\.");
      vector<string> str_arr(
                      sregex_token_iterator(version_str.begin(), version_str.end(), regex, -1),
                      sregex_token_iterator()
                      );
      vector<int> ret_arr;
      for (auto &s: str_arr) {
          ret_arr.push_back(stoi(s));
      }
      return ret_arr;
    }


    int version_cmp_(string v1,string v2) {
      vector<int> lista = string_to_int_arr_(v1);
      vector<int> listb = string_to_int_arr_(v2);
      int len_a = lista.size();
      int len_b = listb.size();
      int minab = (len_a<len_b) ? (len_a) : (len_b);
      int ii=0;
      while(ii<minab) {
        if (lista[ii]!=listb[ii]) {
          break;
        } else {
          ii = ii+1;
        }
      }
      if (ii<minab) {
        return lista[ii]-listb[ii];
      } else if (ii==minab) {
        if (len_a >minab) {
          return 1;
        } else if (len_b > minab) {
          return -1;
        } else {
          return lista[minab-1]-listb[minab-1];
        }
      }
      return 9999;
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
