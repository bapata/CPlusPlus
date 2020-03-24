#include <iostream>
using namespace std;

int max_unique_list_len(int mylist[],int mylist_size) {
  int max_index=0;
  int max_len=0;
  int ret_len=0;

  for (int index=0;index<mylist_size;index++) {
    for (int jj=index+1;jj<mylist_size;jj++) {
      max_index=index;
      max_len++;
      if (mylist[jj] == mylist[index]) {
        if (max_len>ret_len) {
          ret_len = max_len;
          max_len=0;
        }
        break;
      }
    }
  }
  return ret_len;
}


int main() {
  static int mydata[] = { 5,1,2,3,4,5,3,2,6 };
  int max_len = max_unique_list_len(mydata,sizeof(mydata)/sizeof(mydata[0]));
  cout << "\nMAX len is " << max_len << endl;
  return 0;
}
