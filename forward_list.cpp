#include <forward_list>
#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <experimental/iterator>

using namespace std;
void print_vector(vector<int> v) {
     copy(v.begin(),
         v.end(),
         experimental::make_ostream_joiner(cout, " "));
     cout << endl;
}

void print_list(list<int> lint) {
         copy(lint.begin(),
         lint.end(),
         experimental::make_ostream_joiner(cout, " "));
     cout << endl;
}
void print_flist(forward_list<int> lint) {
         copy(lint.begin(),
         lint.end(),
         experimental::make_ostream_joiner(cout, " "));
     cout << endl;
}

int main() {
    vector<int> data{1,2,3,4,5};
    print_vector(data);
    reverse(data.begin(),data.end());
    print_vector(data);
    list<int> lst1{1,2,3,4,5};
    print_list(lst1);
    forward_list<int> lst2{1,2,3,4,5};
    print_flist(lst2);

    auto it1=lst1.begin();
    auto it2 =lst2.begin();

    lst1.reverse();
    print_list(lst1);
    lst2.reverse();
    print_flist(lst2);


}
