#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, k;
struct edge {
  int so, dest, w;
  edge() {}
  edge(int a, int b, int c) {so=a; dest=b; w=c;}
};
struct comp {
  bool operator()(const edge& a, const edge& b) {
    return a.w < b.w;
  }  
} asc;  
vector<edge> e;
vector< vector<int> > adj;
vector< pair<int,int> > ne;
vector<int> con;
int curr, sol;
void dfs(int x) {
  con[x] = curr;
  for(int i = 0; i < adj[x].size(); ++i)
    if(!con[ adj[x][i] ])
      dfs(adj[x][i]);
}
bool ok(int x, int y) {
  fill(con.begin(), con.end(), 0);
  adj.clear(); adj.resize(n);
  curr = 1;
  x = upper_bound(e.begin(), e.end(), edge(0,0, y), asc)-e.begin();
  for(int i = x; i < k; ++i) {
    adj[ e[i].so ].push_back( e[i].dest );
    adj[ e[i].dest ].push_back( e[i].so );
  }
  for(int i = 0; i < n; ++i) if(!con[i]) {dfs(i); ++curr;}
  for(int i = 0; i < m; ++i)
    if(con[ ne[i].first ] == con[ ne[i].second ])
      return false;
  if(x) sol = e[x-1].w; 
  else sol = 0;
  return true;
}   
void solve() {
  int lo = 0, hi = k-1, mid;
  while(lo <= hi) {
    mid = (lo+hi)/2;
    if(ok(mid, e[mid].w)) hi = mid-1;
    else lo = mid+1;
  }
  ok(0, -1);
  printf("%d", sol);
}
void input() {
  scanf("%d %d %d", &n, &k, &m);
  adj.resize(n);
  con.resize(n);
  e.resize(k);
  for(int i = 0; i < k; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c); --a; --b;
    e[i] = edge(a, b, c);
  }
  sort(e.begin(), e.end(), asc);
  for(int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b); --a; --b;
    ne.push_back(make_pair(a, b));
  }
}
int main() {
  input();
  solve();
  //scanf("\n");
  return 0;
}
