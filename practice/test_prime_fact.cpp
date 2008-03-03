#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
int n, a[10];
int solve(int x) {
  for(int i = 1; i < 100000; ++i) {
    int cnt = 0, potpun = 0;
    for(int j = 1; j*j <= i; ++j)
      if(j*j == i) potpun = 1;
      else if(i % j == 0) ++cnt;
    if(x == 2*cnt + potpun) return i;
  }  
  return -1;
}
int pot(int x, int k) { 
  int ret = 1;
  for(int i = 0; i < k; ++i) ret *= x;
  return ret;
}  
int main() {
  const int fct[] = {2, 3, 5, 7, 9, 11, 13, 17, 19, 23, 29, 31, 37};
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
  int greedy = 1, f = 1;
  for(int i = 0; i < n; ++i) {
    greedy *= pot(fct[i], a[i]-1);
    printf("[%d^%d]", fct[i], a[i]);
    f *= a[i];
  }  
  int sol = solve(f);
  printf("Greedy: %d\nPravo: %d\n", greedy, sol);
  if(greedy == sol) printf("TOCNO!"); else printf("KRIVO!");
  scanf("\n");
  return 0;
}


