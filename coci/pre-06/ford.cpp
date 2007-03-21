#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int m1, m2, m, n;
struct edge {
  int so, dest, w;
  edge() {}
  edge(const int& a, const int&b, const int& c) {so = a; dest = b; w = c;}
};  
vector<edge> e;
vector<int> dist;
void solve() {
  dist[0] = 0;
  for(int i = 0; i < n; ++i) 
    for(int j = 0; j < m; ++j)
      dist[ e[j].dest ] <?= dist[ e[j].so ] + e[j].w;
  printf("%d", dist[n-1]);
}  
void input() {
  scanf("%d %d %d", &n, &m1, &m2); m = m1+m2;
  dist = vector<int>(n, 1000000000); e.reserve(m);
  for(int i = 0; i < m1; ++i) {
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    e.push_back(edge(--a, --b, -c));
  }  
  for(int i = 0; i < m2; ++i) {
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    e.push_back(edge(--a, --b, c));
  }
}  
int main() {
  input();
  solve();
  scanf("\n");
  return 0;
}  
