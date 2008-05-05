#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#define FC(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define MAX 1005
using namespace std;
stack<int> s;
vector< vector<int> > adj, e;
int n, m;
int score[MAX], L[MAX], D[MAX], boja[MAX], flag[MAX], cost[MAX], dp[MAX], cd, comp;
int rec(int x) {
  int &ret = dp[x];
  if(ret != -1) return ret;
  ret = 0;
  FC(it, e[x])
    ret >?= rec(*it) + cost[x];
  return ret;
}
void construct(int x) {
  cost[ flag[x] ] += score[x];
  FC(it, adj[x])
    if(flag[x] != flag[*it] && flag[x] != -1)
      e[ flag[x] ].push_back( flag[*it] );
}
int dfs(int x) {
  L[x] = D[x] = cd++;
  boja[x] = 1;
  s.push(x);
  FC(it, adj[x]) {
    if(D[*it] == -1)
      L[x] <?= dfs(*it);
    else if(boja[*it] == 1)
      L[x] <?= D[*it];
  }
  if(L[x] == D[x]) {
    int u;
    do {
      u = s.top();
      s.pop();
      flag[u] = comp;
    } while(u != x);
    ++comp;
  }
  boja[x] = 2;
  return L[x];
}
int solve() {
  memset(D, -1, sizeof(D));
  memset(flag, -1, sizeof(flag));
  dfs(0);
  
  e.resize(comp);
  for(int i = 0; i < n; ++i)
    if(flag[i] != -1)
      construct(i);
  if(flag[0] == -1) return 0;
  memset(dp, -1, sizeof(dp));
  return rec(flag[0]) + cost[0];
}
void input() {
  int k;
  scanf("%d%d", &n, &k);
  adj.resize(n);
  for(int i = 0; i < k; ++i) {
    int x;
    scanf("%d", &x);
    score[--x] = 1;
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
  input();
  printf("%d\n", solve() );
  return 0;
}
/*
3
2 1 2
2
1 2
1 3


5
5 5 4 3 2 1
8
1 2
2 3
3 2
2 4
1 4
1 5
4 5
4 5
*/
