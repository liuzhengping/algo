#include <cstdio>
#include <iostream>
#define MAX 5002
using namespace std;
int n, m;
long long a[MAX], dp[MAX];
void solve() {
  dp[0] = 1;
  for(int i = 1; i <= n; ++i) 
    for(int j = 0; j < m; ++j)
     if(a[j] <= i) 
      dp[i] += dp[i-a[j]]; 
  printf("%lld", dp[n]);
}  
void input() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; ++i) scanf("%lld", &a[i]);
}  
int main() {
  input();
  solve();
  scanf("\n");
  return 0;
}  
