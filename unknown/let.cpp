#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
const long long inf = 1000000000000000000LL;
int n, k, t;
int cost[200005][51];
LL dp[2][51], sol;
void solve() {
  int curr = 0, last = 1;
  for(int i = 1; i < k; ++i)
    dp[last][i] = -inf;
  dp[last][0] = cost[0][0];
  for(int i = 1; i <= t; ++i) {
    for(int j = 0; j < k; ++j) dp[curr][j] = -inf;
    for(int j = 0; j < k; ++j) {
      if(j >= 0) dp[curr][j] >?= dp[last][j-1] + cost[i][j];
      dp[curr][j] >?= dp[last][j] + cost[i][j];
      if(j+1 < k) dp[curr][j] >?= dp[last][j+1] + cost[i][j];
    }
    curr ^= 1;
    last ^= 1;
  }
  for(int i = 0; i < k; ++i)
    sol >?= dp[last][i];

  printf("%lld\n", sol);
}
void input() {
  scanf("%d%d%d", &k, &n, &t);
  for(int i = 0; i < n; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    cost[c][--b] += a;
  }
}
int main() {
  input();
  solve();
  return 0;
}
