#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int n, st, sol, maxi = 0;
vector<vector<pair<int, int> > > adj;
int dfs(int x, int p) {
  int max1 = 0, max2 = 0;
  for(int i = 0; i < adj[x].size(); ++i)
    if(adj[x][i].first != p) {
      int d = dfs(adj[x][i].first, x) + adj[x][i].second;
      if(d > max1) {
        max2 = max1; max1 = d;
      }
      else if(d > max2) max2 = d; 
    }
  maxi >?= max1 + max2;
  return max1;
} 
void solve() {
  dfs(st, -1);
  sol-=maxi;
}
void input() {
  scanf("%d %d", &n, &st); --st;
  adj.resize(n);
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
