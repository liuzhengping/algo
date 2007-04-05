#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<pair<int, int> > > adj;
int n, sol;
int dfs(int x, int dad) {
  int best = 0, best1 = 0, best2 = 0;
  for(int i = 0; i < adj[x].size(); ++i)
    if(adj[x][i].first != dad) {
      int best = dfs(adj[x][i].first, x) + adj[x][i].second;
      if(best > best1) {
        best2 = best1;
        best1 = best;
      }
      else if(best > best2) best2 = best;  
    }
  sol >?= best1 + best2;
  return best1;
}  
void input() {
  scanf("%d", &n);
  adj.resize(n);
  for(int i = 0; i < n-1; ++i) {
    int a, b, c; scanf("%d%d%d", &a, &b, &c);
    --a; --b;
    adj[a].push_back(make_pair(b, c));
    adj[b].push_back(make_pair(a, c));
  }
  dfs(0, -1);
  printf("%d", sol);  
}  
int main() {
  input();
  //scanf("\n");
  return 0;
}  
