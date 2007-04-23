#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100003
using namespace std;
int n, m, g1, g2, c, st, en, up, q;
vector<vector<int> > adj;
int bio[MAX];
int dfs(int x)  {
  if(x == en) return 1;
  bio[x] = 1;
  for(int i = 0; i < adj[x].size(); ++i)
    if(!bio[adj[x][i]])
      if(dfs(adj[x][i])) return 1;
  return 0;
}  
void solve() {
  fill(bio, bio+n, 0);
  if(up == 1) {
    adj[g1].erase(remove(adj[g1].begin(), adj[g1].end(), g2), adj[g1].end());
    adj[g2].erase(remove(adj[g2].begin(), adj[g2].end(), g1), adj[g2].end());
  }
  else bio[c] = 1;
  if(dfs(st)) printf("da\n");
  else printf("ne\n");
  if(up == 1) {
    adj[g1].push_back(g2);
    adj[g2].push_back(g1);
  }  
}  
void input() {
  scanf("%d%d", &n,&m);
  adj.resize(n);
  for(int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }  
  scanf("%d", &q);
  for(int i = 0; i < q; ++i) {
    scanf("%d", &up);
    if(up == 1) {
      scanf("%d%d%d%d", &st, &en, &g1, &g2); --st; --en; --g1; --g2;
    }
    else {
      scanf("%d%d%d", &st, &en, &c); --st; --en; --c;
    }
    solve();    
  }  
}  
int main() {
  double cl = clock();
  input();
  //scanf("\n");
  printf("\n%lf", clock()-cl);
  return 0;
} 
/*
13 15
1 2
2 3
3 5
2 4
4 6
2 6
1 4
1 7
7 8
7 9
7 10
8 11
8 12
9 12
12 13
5
1 5 13 1 2
1 6 2 1 4
1 13 6 8 7
2 13 6 7
2 13 6 8
*/ 
