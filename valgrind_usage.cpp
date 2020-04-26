#include <stdlib.h>
// g++ valgrind_usage.cpp -o valgrind_usage
// valgrind -q --leak-check=full valgrind_usage
// If you comment out free(p) line, then valgrind will complain

int main(int argc,char **argv) {
  char *p = (char *)malloc(argc);
  free(p);
}
