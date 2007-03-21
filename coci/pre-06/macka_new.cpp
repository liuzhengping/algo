#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int inf = 1000000000;
int n, a, b;
vector<vector<int> > adj;
void solve() {
  vector<int> dista(n, inf), distb(n, inf);
  dista[a] = 0; distb[b] = 0;
  queue<int> q;
  for(q.push(a); !q.empty(); q.pop()) {
    int x = q.front();
    for(int i = 0; i < adj[x].size(); ++i)
      if(dista[ adj[x][i] ] == inf) {
        dista[ adj[x][i] ] = dista[x] + 1;
        q.push(adj[x][i]);
      }  
  }
  int sol = 0;
  for(q.push(b); !q.empty(); q.pop()) {
    int x = q.front(); sol >?= dista[ x ];
    for(int i = 0; i < adj[x].size(); ++i)
      if(distb[ adj[x][i] ] == inf) {
        distb[ adj[x][i] ] = distb[x] + 1;
        if(distb[x] < dista[x]) q.push(adj[x][i]);
      }  
  } 
  printf("%d", sol); 
}  
void input() {
  scanf("%d %d %d", &n, &a, &b); --a; --b;
  adj.resize(n); 
  for(int i = 0; i < n; ++i) {
    int k; scanf("%d", &k);
    for(int j = 0; j < k; ++j) {
      int x; scanf("%d", &x); --x;
      adj[i].push_back(x);
    }   
  }  
}  
int main() {
  input();
  solve();
  scanf("\n");
  return 0;
}  
