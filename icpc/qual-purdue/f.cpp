#include <cstdio>
#include <cstring>

#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

int n, m;

vector<vector<int> > a;

int dfs(int u, int s, vector<bool>& vis) {
  int ret = 0;
  for (vector<int>::iterator v = a[u].begin(); v != a[u].end(); ++v) {
    if (*v == s)
      ++ret;
    else if (!vis[*v]) {
      vis[*v] = true;
      ret += dfs(*v, s, vis);
      vis[*v] = false;
    }
  }
  return ret;
}

int main() {
  scanf("%d%d", &n, &m);
  a.resize(n);
  for (int i = 0; i < m; ++i) {
    int from, to;
    scanf("%d%d", &from, &to);
    a[from].push_back(to);
  }

  // make the graph simple
  for (int i = 0; i < n; ++i) {
    sort(a[i].begin(), a[i].end());
    a[i].erase(unique(a[i].begin(), a[i].end()), a[i].end());
    a[i].erase(remove(a[i].begin(), a[i].end(), i), a[i].end());
  }

  int sol = 0;
  for (int i = 0; i < n - 1; ++i) {
    vector<bool> vis(n);
    vis[i] = true;
    sol += dfs(i, i, vis);

    a[i].clear();
    for (int u = 0; u < n; ++u)
      a[u].erase(remove(a[u].begin(), a[u].end(), i), a[u].end());
  }
  printf("%d\n", sol);
  return 0;
}
