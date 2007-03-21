#include <cstdio>
#include <iostream>
#define MAX 30002
using namespace std;
int main() {
  int n, m, a[MAX];
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) a[i] = i;
  for(int i = 0; i < m; ++i) {
    int x; char c[2];
    scanf("%d %s", &x, &c); --x; 
    if(0[c] == 'D') {
      if(x == n-1) continue;
      swap(a[x], a[x+1]);
    }
    else {
      if(!x) swap(a[0], a[n-1]);
      else swap(a[x], a[x-1]);
    }    
  }
  printf("%d", a[0]+1);  
  scanf("\n");
  return 0;
}  
