#include <cmath>
#include <cstdio>
#include <cstring>
#include <cctype>

#include <algorithm>
#include <limits>
#include <utility>
#include <vector>

#define MAXN 2503

#define SQ(x) ((x)*(x))

using namespace std;

typedef pair<int, int> coord_t;

const int infty = 0x3f3f3f3f;

int a[MAXN][MAXN];
int d[MAXN];
int p[MAXN];
int vis[MAXN];
int n, m;

int find_min() {
  int min = infty;
  int min_ind = -1;
  for (int i = 0; i < n; ++i)
    if (!vis[i] && d[i] < min) {
      min = d[i];
      min_ind = i;
    }
  return min_ind;
}

void solve() {
  fill(d, d + n, infty);
  memset(p, -1, sizeof(p));
  memset(vis, 0, sizeof(vis));
  d[0] = 0;
  for (;;) {
    int u = find_min();
    vis[u] = 1;
    if (u == -1 || u == 1)
      break;
    for (int v = 1; v < n; ++v)
      if (v != u && !vis[v]) {
	int cost = d[u] + a[u][v];
	if (cost < d[v]) {
	  d[v] = cost;
	  p[v] = u;
	}
      }
  }

  if (p[1] == 0)
    printf("-\n");
  else {
    vector<int> s;
    for (int v = p[1]; v > 0; v = p[v])
      s.push_back(v);
    for (int i = (int)s.size() - 1; i >= 0; --i)
      printf("%d\n", s[i] - 2);
  }
}

int calc_w(const coord_t& c1, const coord_t& c2) {
  return SQ(c1.first - c2.first) + SQ(c1.second - c2.second);
}

void input() {
  scanf("%d", &n);
  n += 2;
  vector<coord_t> coords(n);
  for (int i = 2; i < n; ++i)
    scanf("%d%d", &coords[i].first, &coords[i].second);
  coord_t& start = coords[0];
  coord_t& end = coords[1];
  scanf("%d%d%d%d", &start.first, &start.second, &end.first, &end.second);

  for (int i = 2; i < n; ++i) {
    for (int j = i + 1; j < n; ++j)
      a[i][j] = a[j][i] = calc_w(coords[i], coords[j]);
    a[0][i] = calc_w(start, coords[i]);
    a[i][0] = infty;
    a[i][1] = calc_w(coords[i], end);
    a[1][i] = infty;
  }
  a[0][1] = calc_w(start, end);
}

int main() {
  input();
  solve();
  return 0;
}
