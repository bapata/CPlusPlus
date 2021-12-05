#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
https://mathworld.wolfram.com/NarcissisticNumber.html
*/

#define SIZE 256
bool is_armstrong(int x) {

  char temp[SIZE];
  sprintf(temp,"%d",x);
  int mylen = strlen(temp);

  int ii=0;
  int sum=0;
  while (ii<mylen) {
    int num = temp[ii]-'0';
    sum = sum + pow(num,mylen);
    ii++;
  }
  return (x==sum);
}

int main(int argc, char **argv) {
  if (argc<=1) {
    printf("\nUSAGE: <this-script> <number>\n");
  }
  if(is_armstrong(atoi(argv[1]))) {
    printf("%s is a armstrong number\n",argv[1]);
  } else {
    printf("%s is NOT a armstrong number\n",argv[1]);
  }
}
