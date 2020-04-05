#include <iostream>
#include <string>

// Constructs Binary search tree and provides various methods to traverse bst
using namespace std;
class BinaryTree {
  private:
    typedef string Mydatatype;
    struct Node {
      Mydatatype data;
      Node *left;
      Node *right;
    };
    Node *mytree;
    Node *insert(Node *atree, Mydatatype adata) {
      // first entry
      if (atree == NULL) {
        atree = new Node;
        atree->data = adata;
        atree->left = NULL;
        atree->right= NULL;
        return atree;
      }
      // non-null tree
      if (adata < atree->data) {
          atree->left  = insert(atree->left, adata);
      }
      else if (adata >= atree->data)  {
          atree->right = insert(atree->right, adata);
      }
      return atree;
    }
    bool search(Node *atree, Mydatatype adata) {
        if (atree== NULL)
            return false;

        if (atree->data == adata)
            return true;

        bool res1 = search(atree->left, adata);
        if(res1) return true; // node found, no need to look further

        bool res2 = search(atree->right, adata);
        return res2;
    }
    void inorder(Node *atree) {
      if (atree==NULL) {
        return;
      }
      inorder(atree->left);
      cout << atree->data << endl;
      inorder(atree->right);
    }

  public:
    BinaryTree() { mytree = NULL; }
    BinaryTree(Mydatatype adata) {
      mytree = new Node;
      mytree->data = adata;
      mytree->left = NULL;
      mytree->right= NULL;
    }
    bool search_data(Mydatatype adata) {
      return search(mytree, adata);
    }
    void inorder_traversal(void) {
      inorder(mytree);
    }
    void insert_data(Mydatatype adata) {
      Node *new_tree = insert(mytree,adata);
      mytree = new_tree;
    }

    ~BinaryTree() { }

};

int main() {
  static string cities[] = {"cupertino","sunnyvale","chicago","austin","dallas","atlanta"};
  BinaryTree b1(cities[0]);
  for(int ii=1;ii<sizeof(cities)/sizeof(cities[0]);ii++) {
    b1.insert_data(cities[ii]);
  }
  b1.inorder_traversal();

  string myname = cities[0];
  if(b1.search_data(myname)) {
    cout << "Found " << myname << endl;
  } else {
    cout << "NOT Found " << myname << endl;
  }
}
