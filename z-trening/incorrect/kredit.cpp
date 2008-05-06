#include <cstdio>
#include <iostream>
#include <queue>
#define MAX 205
using namespace std;
typedef pair<int, int> par;
const int inf = 1000000000;
char grid[MAX][MAX];
int font[MAX][MAX], traf[MAX][MAX], minsol = inf, maxsol, n, m, k;
const par dd[] = {make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0) };
queue<par> q;
par operator+(const par& a, const par& b) {
  return make_pair(a.first+b.first, a.second+b.second);
}
int ok(const par& p) {
  return p.first >= 0 && p.first < n && p.second >= 0 && p.second < m;
}
void bfs(int dist[MAX][MAX]) {
  for(; !q.empty(); q.pop()) {
    par u = q.front();
    for(int i = 0; i < 4; ++i) {
      par np = u + dd[i];
      if( !ok(np) ) continue;
      if( dist[np.first][np.second] == -1 && grid[np.first][np.second] != 'X') {
        dist[np.first][np.second] = dist[u.first][u.second] + 1;
        q.push(np);
      }
    }
  }
}
void solve() {
  memset(font, -1, sizeof(font));
  memset(traf, -1, sizeof(traf));
  
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      if(grid[i][j] == 'T') {
        traf[i][j] = 0;
        q.push( make_pair(i, j) );
      }
  bfs(traf);
  
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      if(grid[i][j] == 'F') {
        font[i][j] = 0;
        q.push( make_pair(i, j) );
      }
  bfs(font);
  
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      if(traf[i][j] != -1 && font[i][j] != -1 && font[i][j] <= k) {
        minsol <?= traf[i][j];
        maxsol >?= traf[i][j];
      }
  printf("%d %d\n", minsol, maxsol);
}
void input() {
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0; i < n; ++i)
    scanf("%s", &grid[i]);
}
int main() {
  input();
  solve();
  return 0;
}