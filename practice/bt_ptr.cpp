#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int n;
struct node {
  node *l, *r;
  int v;
  node() {v = -1; l = NULL; r = NULL;}
  node(int x) {v = x; l = NULL; r = NULL;} 
};
struct tree {
  vector<node> t;
  node root;
  void preorder(node *x) {
    if(x == NULL) return;
    printf("%d", x->v);
    preorder(x->l);
    preorder(x->r);
  }  
  void insert(int x) {
    if(root.v == -1) {
      root.v = x; return;}
    node *curr, *last;
    curr = &root;
    while(curr != NULL) {
      if(x <= curr->v) curr = curr->l;  
      else curr = curr->r;  
    }
    curr = new node(x);
  }
  tree() {
    
  }    
};    
int main() {
  scanf("%d", &n);
  tree t;
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    t.insert(x);
    t.preorder(&t.root);
  }  
  scanf("\n");
  return 0;
}  
