#include <cstdio>
#include <cstring>
#define MAX 100000
using namespace std;
char a[MAX], in[100], pre[100], post[100];
int int_path, ext_path, depth;
void preorder(int x) {
  if(!a[x]) return;
  
    char s[2]; s[0] = a[x]; s[1] = '\0';
    strcat(pre, s);
  preorder(2*x);
  preorder(2*x+1);
}  
void inorder(int x) {
  if(!a[x]) return;
  
  inorder(2*x);
    char s[2]; s[0] = a[x]; s[1] = '\0';
    strcat(in, s);
  inorder(2*x+1);
}
void postorder(int x) {
  if(!a[x]) return;
  
  postorder(2*x);
  postorder(2*x+1);
    char s[2]; s[0] = a[x]; s[1] = '\0';
    strcat(post, s);
}
void path(int x, int dist) {
  if(!a[x]) {ext_path += dist; return; }
  int_path += dist;
  depth >?= dist;
  path(2*x, dist+1);
  path(2*x+1, dist+1);
}    
void input() {
  static char s[100];
  scanf("%s", &s);
  a[1] = s[0];
  for(int i = 1; i < strlen(s); ++i) {
    int x = 1;
    while(a[x]) {
      if(s[i] <= a[x]) x = 2*x;
      else x = 2*x+1;
    }  
    a[x] = s[i];
  }  
  in[0] = pre[0] = post[0] = '\0';
}  
int main() {
  input();
  preorder(1);
  inorder(1);
  postorder(1);
  printf("Preorder:  %s\n", pre); 
  printf("Inorder:   %s\n", in);  
  printf("Postorder: %s\n", post);
  path(1, 0);
  printf("Internal Path: %d\n", int_path);  
  printf("External Path: %d\n", ext_path); 
  printf("Depth: %d", depth);
  scanf("\n");
  return 0;
}  
