#include <iostream>
#include <stdio.h>
int main() {
  unsigned char n = 0b10101011;

  int nu_of_bits = sizeof(n)*8;
  int sum=0;
  int my_ander=0x01;

  for (int ii=0;ii<nu_of_bits;ii++) {
    unsigned char answer = my_ander & n;
    n = n >> 1;
    printf("\npop");
    sum = sum + answer;
  }
  printf("\nTotal number of ones in %x is %x\n",n,sum);
  return 0;
}
