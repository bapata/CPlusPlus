#include <iostream>

using namespace std;

void swap(int *x,int *y) {
  int tmp = *x;
  *x=*y;
  *y=tmp;
}

int get_second_max(int a[],int count) {
  int max=-1,second_max=-1;

  for(int ii=0;ii<count;ii++) {
    if (a[ii]>max) {
      second_max=max;
      max=a[ii];
    } else if (max > a[ii] >second_max) {
      second_max=a[ii];
    }
  }
	return second_max;
}

int main() {
  static int a[] = { 2,1,3,3,4,5,6,6 };

  cout << "\nSecond Max is "<<get_second_max(a,sizeof(a)/sizeof(a[0])) << endl;

}
