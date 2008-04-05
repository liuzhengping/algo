#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#define MAX 1002
using namespace std;
vector<vector<int> > adj, inv;
int n, m, k;
char from_it[MAX], to_it[MAX], cost[MAX], used[MAX], backup[MAX], susj[MAX];
inline bool strong(int x) { return from_it[x] && to_it[x]; }
bool kraj() {
  for(int i = 0; i < n; ++i)
    if(!used[i]) return false;
  return true;
}  
void dfs(int x) {
  if(from_it[x]) return ;
  from_it[x] = 1;
  for(int i = 0; i < adj[x].size(); ++i)
    if(!used[ adj[x][i] ] && !from_it[ adj[x][i] ])
      dfs(adj[x][i]);
}
void inv_dfs(int x) {
  if(to_it[x]) return ;
  to_it[x] = 1;
  for(int i = 0; i < inv[x].size(); ++i)
    if(!used[ inv[x][i] ] && !to_it[ inv[x][i] ])
      inv_dfs(inv[x][i]);
}   
void discover(int x) {
  memset(susj, 0, sizeof susj);
  memset(from_it, 0, sizeof from_it);
  memset(to_it, 0, sizeof to_it);
  dfs(x);
  inv_dfs(x);
} 
int solve(int x) {
  memcpy(backup, used, sizeof backup); //save
  discover(x);
  int spread = 0;
  for(int i = 0; i < n; ++i)
    if( strong(i) ) {
      used[i] = 1;
      spread += cost[i];
    }
  int ret = spread; 
  for(int i = 0; i < n; ++i)
    if( strong(i) )
      for(int j = 0; j < adj[i].size(); ++j)
        if( !used[ adj[i][j] ] )
          susj[ adj[i][j] ] = 1;
  for(int i = 0; i < n; ++i) {
    if(!susj[i]) continue;
    ret = max(ret, spread + solve(i) );
  }   
  memcpy(used, backup, sizeof used); //loadaj
  return ret;
}   
void input() {
  scanf("%d%d", &n, &k);
  adj.resize(n);
  inv.resize(n);
  for(int i = 0; i < k; ++i) {
    int x; 
    scanf("%d", &x); --x;
    cost[x] = 1;
  } 
  scanf("%d", &m); 
  for(int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a; --b;
    adj[a].push_back(b);
    inv[b].push_back(a);
  }  
}  
int main() {
  input();
  printf("%d\n", solve(0) );
  return 0;
}


