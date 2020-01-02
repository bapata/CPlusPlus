#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef struct tagCoin {
  int cent_value;
  string cent_str;
} Coin;

map<char, Coin> m = { {'Q',{25, "quarters"} },
                      {'D',{10, "dimes"}    },
                      {'N',{5, "nickels"}   },
                      {'P',{1, "pennis"}   }
                    };

map<char,int> get_coin_count(int value_in_cents) {
  map<char,int> ret_val;

  while(value_in_cents) {

    int quarter_count = value_in_cents/25;
    if(quarter_count>0) {
      ret_val['Q'] = ret_val['Q'] + quarter_count;
    }
    value_in_cents = value_in_cents - (quarter_count * 25);

    int dime_count = value_in_cents/10;
    if (dime_count>0) {
      ret_val['D'] = ret_val['D'] + dime_count;
    }
    value_in_cents = value_in_cents - (dime_count * 10);

    int nickel_count = value_in_cents/5;
    if (nickel_count>0) {
      ret_val['N'] = ret_val['N'] + nickel_count;
    }
    value_in_cents = value_in_cents - (nickel_count * 5);

    int penny_count = value_in_cents/1;
    if (penny_count>0) {
      ret_val['P'] = ret_val['P'] + penny_count;
    }
    value_in_cents = value_in_cents - (penny_count * 1);
  }
  return ret_val;

}

int main(int argc,char **argv) {
  if(argc!=2) {
    cout << "\nUSAGE: <this-script> <cents>\n";
    exit(0);
  }

  int value_in_cents = atoi(argv[1]);
  map<char,int> coin_count = get_coin_count(value_in_cents);
  for (map<char, int>::iterator it = coin_count.begin(); it != coin_count.end(); it++) {
    cout << it->first << ":" << it->second << endl;
  }
}
