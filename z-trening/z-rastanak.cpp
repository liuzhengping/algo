#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAX 105
using namespace std;
const int inf = 100000000;
int n, m, bus, taxi, house[MAX], dp[1005][1005];
int brute_dp() {
  for(int i = 0; i <= m; ++i)
    for(int j = 0; j <= m; ++j)
      dp[i][j] = inf;
  for(int i = 0; i <= m; ++i) dp[0][i] = 0;
  printf("((%d))", m);
  for(int i = 0; i <= m; ++i) {
    //ako bus ne postavim na i-to mjesto onda je stanje isto kao prije
    for(int j = 0; j <= i; ++j) dp[i][j] <?= dp[i-1][j];
    //ako bus postavim na i-to mjesto onda je
    //probam sva moguca stanja od zadnjeg postavljanja busa
    for(int j = 0; j < i; ++j) {
      int cost = 0;
      for(int k = j; k <= i; ++k)
        cost += house[k]*min(i-k, k-j)*taxi; 
      //printf("cost(%d %d) = %d\n", j, i, cost);
      dp[i][j] <?= dp[i-1][j] + cost + bus;  
    }
  }
  int sol = inf;
  for(int j = 0; j < m; ++j) {
      int cost = dp[m-1][j];
      for(int k = j+1; k < m; ++k)
        cost += house[k]*(k-j)*taxi; 
      dp[m][j] <?= cost;  
    }
  for(int i = 0; i <= m; ++i) sol <?= dp[m][i];
  printf("%d\n", sol);
  for(int i = 0; i <= m; ++i, printf("\n"))
    for(int j = 0; j <= m; ++j)
      printf("%3d", (dp[j][i] == inf) ? -1 : dp[j][i]);
}
int main() {
  scanf("%d%d%d", &n, &bus, &taxi);
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x); m >?= x;
    ++house[x];
  }
  brute_dp();
  scanf("\n");
  return 0;
}
/*
3
1000 1
3 8 11
*/
