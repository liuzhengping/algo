#include <cstdio>
#include <iostream>
#include <vector>
#define MAX 105
using namespace std;
const int inf = 1000000000;
vector<vector<int> > adj;
int points[MAX], dp[MAX][MAX][2], A, B, n, m, q;
int rec(int a, int b, int who) {
  int &ret = dp[a][b][who];
  if(ret != -1) return ret;
  int ok = 0;
  if(who) {
    ret = 0;
    for(int i = 0; i < adj[a].size(); ++i)
      if(adj[a][i] != b) {
        ok = 1;
        ret >?= rec(adj[a][i], b, who ^ 1);
      }
    ret += points[a];
  }  
  else {
    ret = inf;
    for(int i = 0; i < adj[b].size(); ++i)
      if(adj[b][i] != a) {
        ret <?= rec(a, adj[b][i], who ^ 1);
        ok = 1;
      }  
    if(ret == inf) ret = 0;
    ret += points[b];
  }  
  return ret;
}  
void input() {
  scanf("%d%d%d", &n, &A, &B);
  --A; --B; adj.resize(n);
  scanf("%d", &q);
  for(int i = 0; i < q; ++i) {
    int x;
    scanf("%d", &x);
    ++points[--x];
  }
  scanf("%d", &m);
  for(int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a; --b;
    adj[a].push_back(b);
  }      
}  
int main() {
  memset(dp, -1, sizeof dp);
  input();
  printf("%d", rec(A, B, 0));
  scanf("\n");
  return 0;
}


