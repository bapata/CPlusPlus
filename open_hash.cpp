#include <iostream>
#include <string>
using namespace std;

class Myhash {
  private:
    static const int MAX_DEFAULT_SIZE=26;
    int table_len;
    struct Node {
      string data;
      Node *next;
    };
    Node **table;

    int hash_function(string name) {
      return tolower(name[0])-'a';
    }
  public:
    Myhash() {
      table_len = MAX_DEFAULT_SIZE;
      table = new Node*[table_len];
      for (int ii=0;ii<table_len;ii++) {
        table[ii]=NULL;
      }
    }
    ~Myhash() {
      delete []table;
    }
    void add_to_hash(string name) {
      int index = hash_function(name);
      if (table[index]==NULL) {
        Node *tmp = new Node;
        tmp->data=name;
        tmp->next = NULL;
        table[index]=tmp;
      } else {
        Node *curr_ptr = table[index];
        while(curr_ptr->next!=NULL) {
          curr_ptr = curr_ptr->next;
        }
        Node *tmp = new Node;
        tmp->data=name;
        tmp->next = NULL;
        curr_ptr->next = tmp;
      }
    }
    void print_hash(void) {
      for (int ii=0;ii<table_len;ii++) {
        cout << "Index: " << ii << " : ";
        Node *curr_ptr = table[ii];
        while(curr_ptr!=NULL) {
          cout << curr_ptr->data << ", ";
          curr_ptr = curr_ptr->next;
        }
        cout << "\n";
      }
    }
};

// open hash demo
int main(int argc,char **argv) {
  Myhash h1;
  static string names[]={"dhoni","sachin","irfan","kapil","gavaskar","srikant","kumble","ganguly","raina","jadeja","maninder","bedi"};
  for(int ii=0;ii<sizeof(names)/sizeof(names[0]);ii++) {
    h1.add_to_hash(names[ii]);
  }
  h1.print_hash();
}
