#include <iostream>
using namespace std;

template<class T>
struct SNode {
  private:
    T x;
  public:
    SNode() { x=0; }
    SNode(T myx) { x=myx; }
    ~SNode() { x=-1; }
    T getX() { return x; }
    void setX(T myx) { x=myx; }
};

template<class T>
struct CNode {
  private:
    T x;
  public:
    CNode() { x=0; }
    CNode(T myx) { x=myx; }
    ~CNode() { x=-1; }
    T getX() { return x; }
    void setX(T myx) { x=myx; }
};


int main(int argc,char **argv,char **envp) {
  SNode<int> *p = new SNode<int>(10);
  SNode<int> *q = new SNode<int>(20);

  cout << p->getX() <<endl;
  cout << q->getX() <<endl;
}
