#include <stdio.h>

// buggy

int int_arr_cmp(int *a,int alen,int *b,int blen) {
  int ii=0,jj=0;

  while (ii<alen && jj<blen) {
    if (a[ii] == b[jj]) {
      ii++;jj++;continue;
    } else {
       return a[ii]-b[jj];
    }
  }
  if (ii<alen && jj<blen) {
    return a[ii]-b[jj];
  } else if (ii<alen) {
    return a[ii];
  } else {
    return b[jj];
  }
}

int main() {
  static int x[] = { 1 };
  static int y[] = { 1 ,3};

  int res = int_arr_cmp(x,sizeof(x)/sizeof(x[0]), y,sizeof(y)/sizeof(y[0]));
  if (res==0) {
    printf("x is equal to y");
  } else if (res>0) {
    printf("x is greater than y");
  } else {
    printf("x is less than y");
  }
  printf("\n%d\n",res);
}
