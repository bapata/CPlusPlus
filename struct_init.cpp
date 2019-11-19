#include <iostream>

// demo code to initialize array of structures

using namespace std;

struct Node {
  int a;
  char b;
  string s;
};

void print_node(Node *nptr, int size) {
  for(int ii=0;ii<size;ii++) {
    cout << nptr[ii].a << ":"<< nptr[ii].b << ":"<< nptr[ii].s << endl;
  }
}


int main() {
  // memory will be allocated from stack. The count will be filled by compiler
  Node node_list[] = { { 1,'a',"one" }, {2,'b',"two"}, {3,'c',"three"} };
  print_node(node_list, sizeof(node_list)/sizeof(node_list[0]));
  // no need to free any memory here because memory allocated for node_list gets freed to OS
  // as soon as main function completes

  const int COUNT=3;
  // This compiles only when you do 'g++ struct_init.cpp -std=c++2a'
  Node *pnode_list = new Node[COUNT] { { 11,'A',"eleven" }, {22,'B',"twentytwo"}, {33,'C',"thirtythree"} };
  // display contents
  print_node(pnode_list,COUNT);
  // free heap memory
  delete []pnode_list;

  // C-language way of allocating memory
  Node *qnode_list = (Node *)malloc(COUNT*sizeof(Node));
  // copy contents from previous list
  for(int ii=0;ii<COUNT;ii++) {
    qnode_list[ii] = pnode_list[ii];
  }
  // display contents
  print_node(qnode_list,COUNT);
  free(qnode_list);

  exit(0);

}
