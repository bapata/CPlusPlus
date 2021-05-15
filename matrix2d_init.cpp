#include <stdio.h>
#include <stdlib.h>

// Allocate memory for mxn matrix and fill with zeros
void get_matrix2d(int ***matrix,int m, int n) {
  int **a = (int **) malloc(m*sizeof(int *)); // allocate rows
  for (int ii=0;ii<m;ii++) {
    a[ii] = (int *) malloc(sizeof(int)*n); // columns
  }

  // initialize
  for (int ii=0;ii<m;ii++) {
    for (int jj=0;jj<n;jj++) {
      a[ii][jj] = 0;
    }
  }
  *matrix = a;
}

// print mxn matrix contents
void print_matrix2d(int **a, int m, int n) {
  for (int ii=0;ii<m;ii++) {
    for (int jj=0;jj<n;jj++) {
        printf(" %d ",a[ii][jj]);
    }
    printf("\n");
  }
}

// invoke
int main() {
  int **mymatrix;
  int p=4,q=5;
  get_matrix2d(&mymatrix,p,q);
  print_matrix2d(mymatrix,p,q);
}
