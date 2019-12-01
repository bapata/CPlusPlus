#include <iostream>

// Construct linked list, and try first,rest,append functions
//            +----+   +----+   +----+
//front_ptr ->| dn +-->| d2 +-->| d1 +-->NULL
//            +----+   +----+   +----+
using namespace std;

typedef int my_data_type ;

// Each node contains data and pointer to next such node
typedef struct tagNode {
  my_data_type data;
  tagNode *next_node;
} Node;

// Allocate memory, fill data and return created node
Node *create_node_with_data(my_data_type d) {
  Node *new_node = new Node;
  new_node->data = d;
  new_node->next_node= NULL;
  return new_node;
}

void print_list(Node *head_ptr) {
  Node *walking_ptr = head_ptr;

  while(walking_ptr!=NULL) {
    cout << walking_ptr->data << " ";
    // now that you got the data, release memory
    walking_ptr = walking_ptr->next_node;
  }
}

// Construct and walk linked-list.
// Example usage:
// ./a.out 4 2 5
// 5 2 4

// (first '(1 2 3)) # 1
// (rest '(1 2 3)) # (2 3)
// (append '1 '(2 3)) # (1 2 3)

Node *first(Node *list) {
  Node *tmp = new Node;
  tmp->data = list->data;
  tmp->next_node = NULL;
  return tmp;
}
Node *rest(Node *list) {
  Node *tmp = list;
  list = list->next_node;
  tmp->next_node = NULL;
  delete tmp;
  return list;
}

Node *append_list(Node *first,Node *second) {
  Node *tmp_ptr = first;
  if(first==NULL) {
    return second;
  }

  while(tmp_ptr->next_node!=NULL) {
    tmp_ptr = tmp_ptr->next_node;
  }
  tmp_ptr->next_node = second;
  return first;
}

Node *build_list(my_data_type *data_list,int count) {
  // build list
  my_data_type tmp_data;
  Node *front_ptr = NULL;
  for (int ii=0;ii<count;ii++) {
    tmp_data = data_list[ii];
    Node *new_node = create_node_with_data(tmp_data);
    if (front_ptr) {
      new_node->next_node = front_ptr;
      front_ptr = new_node;
    } else { // first time
      front_ptr = new_node;
    }
  }
  return front_ptr;
}


int main(int argc, char **argv) {

  int *data_list = new int[argc-1];
  int second_data_list[] = { 21, 22, 35 };

  for (int ii=1;ii<argc;ii++) {
    data_list[ii-1] = atoi(argv[ii]);
  }
  Node *front_ptr = build_list(data_list,argc-1);
  Node *other_ptr = build_list(second_data_list,sizeof(second_data_list)/sizeof(second_data_list[0]));

  print_list(front_ptr);
  cout << endl;
  print_list(other_ptr);
  cout << endl;
  Node *appended_list = append_list(front_ptr,other_ptr);
  cout << "Appended List\n";
  print_list(appended_list);

  exit(0);
}
