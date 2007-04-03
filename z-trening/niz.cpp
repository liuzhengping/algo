#include <cstdio>
using namespace std;
int a, b;
int znam(int x) {
  int ret = 0;
  while(x) {ret+= x%10; x/=10;}
  return ret;
}  
int solve(int x) {
  int ret = 0;
  int br = znam(4*x); printf("(%d)", br);
  int lo = x+1, hi = 1000, mid;
  for(int i = 0; i < 30; ++i) {
    mid = (lo+hi)/2;
    printf("Checking %d...", mid);
    if(znam(mid) == br) {lo = mid; printf("OK\n");}
    else {hi = mid;printf("NO\n"); }
  }
  return mid;  
}  
int main() {
  scanf("%d %d", &a, &b);
  int curr = a, next;
  for(int i = 0; i < b; ++i) {
    curr = solve(curr);
    printf("%d\n", curr);
  }  
  scanf("\n");
  return 0;
}  
