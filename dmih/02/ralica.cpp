#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int n, st, sol, maxi = 0;
vector<vector<pair<int, int> > > adj;
vector<int> dist;
void dfs(int x, int p) {
  for(int i = 0; i < adj[x].size(); ++i)
    if(adj[x][i].first != p) {
      dist[ adj[x][i].first ] = dist[x] + adj[x][i].second;
      maxi >?= dist[ adj[x][i].first ];
      dfs(adj[x][i].first, x); 
    }
  
} 
void solve() {
  dist[st] = 0;
  dfs(st, -1);
  sol-=maxi;
}
void input() {
  scanf("%d %d", &n, &st); --st;
  dist.resize(n); adj.resize(n);
  for(int i = 0; i < n-1; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c); --a; --b;
    adj[a].push_back(make_pair(b, c));
    adj[b].push_back(make_pair(a, c));
    sol+=2*c;
  }
}
void ispisi() {printf("%d", sol);}
int main() {
  input();
  solve();
  ispisi();
  //scanf("\n");
  return 0;
}
