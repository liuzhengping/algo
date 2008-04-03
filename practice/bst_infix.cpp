#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int cnt;
struct node {
  char c;
  node* l;
  node* r;
  node() { l = r = NULL; c = 0; }
};
void infix(node* x) {
  if(x == NULL) return ;
  infix(x->l);
  printf("(%c)", x->c);
  infix(x->r);
}  

struct tree {
  node *root;
  node* insert(node* x, char c) {
    if(x == NULL) {
      x = new node();
      x->c = c;
      return x;
    }
    ++cnt;
    if(c <= x->c) x->l = insert(x->l, c);
    else x->r = insert(x->r, c);
    return x;
  } 
  int depth(node* x) {
    
  }   
} t;    
int main() {
  
  string s;
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) t.root = t.insert(t.root, (i+i%23+i%6+i%2+i%17+i%13)%26+'a');
  infix(t.root);
  
  printf("%d\n", cnt);
  scanf("\n");
  return 0;
}


