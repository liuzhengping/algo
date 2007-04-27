#include <cstdio>
#include <iostream>
#define MAX 100
#define bit(x, y) ((y & (1 << (n-x-1))) > 0)
using namespace std;
int n, m; bool bio[MAX];
struct node {
  int op; //0 = ?, 1 = AND, 2 = OR, 3 = XOR
  int prvi, drugi;
  int a[130];
};
node tab[MAX]; 
void ispis() {
  for(int i = 0; i < n; ++i) printf("%c\t", 'A'+i);
  printf("|\t");
  for(int i = 0; i < m; ++i) 
    printf("%c?%c\t", 'A'+tab[i+n].prvi, 'A'+tab[i+n].drugi);
  printf("\n------------------------------------------------------------\n");
  for(int puta = 0; puta < (1 << n); ++puta) {
    for(int i = 0; i < n; ++i) printf("%d\t", bit(i, puta));
    printf("|\t");
    for(int i = 0; i < m; ++i) 
      printf("%d\t", tab[i+n].a[puta]);
    printf("\n");
  }   
}
void dfs(int x) {
  if(!tab[ tab[x].prvi  ].op) dfs(tab[x].prvi );
  if(!tab[ tab[x].drugi ].op) dfs(tab[x].drugi);
  //try_and(tab[x]);
}  
void solve() {
  for(int i = 0; i < m; ++i)
    dfs(n+i);
}   
void input() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < (1 << n); ++i) {
    char s[130];
    scanf("%s", &s);
    for(int j = 0; j < m; ++j)
      tab[n+j].a[i] = s[j]-'0';
  }
  for(int i = 0; i < m; ++i) {
    int x; scanf("%d", &x); x-=11; 
    tab[n+i].prvi = x/10;
    tab[n+i].drugi = x%10;
  }  
}    
int main(){
  input();
  //solve();
   ispis();
   scanf("\n"); 
  return 0;
}
/*
2 3 000 101 101 110 12 12 34
*/


