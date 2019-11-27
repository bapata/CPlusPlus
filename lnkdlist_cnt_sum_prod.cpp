#include <iostream>

// Construct linked list and print contents of the linked list (will be in reverse order)
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

// recursively count nodes
int count_nodes(Node *head_ptr) {
  if (head_ptr ==NULL) {
    return 0;
  } else {
    return (1 + count_nodes(head_ptr->next_node));
  }
  // we should never come here
}

// recursively add up contents of nodes
int sum_of_data(Node *head_ptr) {
  if (head_ptr ==NULL) {
    return 0;
  } else {
    return (head_ptr->data + sum_of_data(head_ptr->next_node));
  }
  // we should never come here
}


// recursively multiple contents of nodes
int prod_of_data(Node *head_ptr) {
  if (head_ptr ==NULL) {
    return 0;
  } else if (head_ptr->next_node == NULL) {
      return head_ptr->data;
  } else {
    return (head_ptr->data * prod_of_data(head_ptr->next_node));
  }
  // we should never come here
}

// helper function for use by max_in_the_list
int max_of_two(int x,int y) {
  if (x>y) {
    return x;
  }
  return y;
}

// recursively find max in the list
int max_in_the_list(Node *head_ptr) {
  if (head_ptr==NULL) {
    return 0;
  } else if (head_ptr->next_node==NULL) {
    return head_ptr->data;
  } else {
    return max_of_two(head_ptr->data,max_in_the_list(head_ptr->next_node));
  }
}

// helper function for use by min_in_the_list
int min_of_two(int x,int y) {
  if (x<y) {
    return x;
  }
  return y;
}

// recursively find min in the list
int min_in_the_list(Node *head_ptr) {
  if (head_ptr==NULL) {
    return 0;
  } else if (head_ptr->next_node==NULL) {
    return head_ptr->data;
  } else {
    return min_of_two(head_ptr->data,min_in_the_list(head_ptr->next_node));
  }
}

// Construct and walk linked-list.
// Example usage:
// ./a.out 4 2 5
// 5 2 4

int main(int argc, char **argv) {
  // assuming user is entering integers
  Node *front_ptr = NULL;

  for (int ii=1;ii<argc;ii++) {
    int tmp_data = atoi(argv[ii]);
    Node *new_node = create_node_with_data(tmp_data);
    if (front_ptr) {
      new_node->next_node = front_ptr;
      front_ptr = new_node;
    } else { // first time
      front_ptr = new_node;
    }
  }

  cout << "Number of nodes in this list is " << count_nodes(front_ptr) << endl;
  cout << "CONTENTS:" <<endl;
  // Walk and print contents
  print_list(front_ptr);
  // Walk and print sum
  cout << "\nSUM:" << sum_of_data(front_ptr) << " " << endl;
  // Walk and print product
  cout << "\nPRODUCT:" << prod_of_data(front_ptr) << " " << endl;
  // Walk and print max
  cout << "\nMAX = " << max_in_the_list(front_ptr) << endl;
  // Walk and print min
  cout << "\nMIN = " << min_in_the_list(front_ptr) << endl;

  // we are not releasing any memory, front_ptr will still points to front of the list
  cout << endl;

  exit(0);
}
