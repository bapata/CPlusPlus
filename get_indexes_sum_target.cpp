#include <iostream>

using namespace std;

class MyList {
  private:
    int target;
    int *list;
    int *index_list;
  public:
  MyList() {
  }
  ~MyList() {
    free(list)
  }
  int set_target(int n) {
    target = n;
  }
  int get_target() {
  }
  int get_list_from_args() {
    list=(int *)malloc(list_size*sizeof(int));
    for (int ii=2;ii<argc;ii++) {
     list[ii]=atoi(argv[ii]);
    }
    return list;
  }
  int get_index_list() {
  }
}

int main(int argc,char **argv) {
// first element is the target
// remaining are part of the list
  Mylist ml = Mylist();
  int list_len = atoi(argv[1]);
  ml.set_target(list_len);
  ml.get_target_from_args(list_len,argv[2]);
}
