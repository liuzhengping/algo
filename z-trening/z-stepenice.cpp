#include <cstdio>
#include <iostream>
#define MAX 100002
using namespace std;
int dp[MAX], n, k;
void solve() {
  dp[0] = 1;
  for(int x = 1; x <= n; ++x) {
    int from = max(x-k-1, -1);
    dp[x] = dp[x-1] - dp[from];
    dp[x] %= 1021987;
    if(x != n) dp[x] += dp[x-1];
  }
  printf("%d", dp[n]);   
} 
void input() {
  scanf("%d%d", &n, &k);
}   
int main() {
  input();
  solve();
  //scanf("\n");
  return 0;
}  
