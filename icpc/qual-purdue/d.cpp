#include <cstdio>
#include <cstring>
#include <cctype>

#include <algorithm>
#include <vector>

using namespace std;

bool solve() {
  int n, m;
  if (scanf("%d%d", &m, &n) != 2)
    return false;

  vector<int> a(n);
  vector<int> b(m, -1); // reverse map
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    b[a[i]] = i;
  }
  sort(a.begin(), a.end());
  
  vector<int> c;
  for (int j = 1; j < n; ++j) {
    for (int i = 0; i < j; ++i) {
      int d = a[j] - a[i];
      if (a[i] < d) {
	bool valid = true;
	int cover = 0;
	for (int x = a[i]; x < m; x += d) {
	  valid &= (b[x] != -1);
	  cover |= (1 << b[x]);
	}
	if (valid) {
	  //printf("%d %d (%d): %d\n", a[i], a[j], d, cover);
	  c.push_back(cover);
	}
      }
    }
  }
  for (int i = 0; i < n; ++i)
    c.push_back(1 << i);

  vector< vector<int> > dp(n + 1);
  for (int i = 0; i < (int)dp.size(); ++i)
    dp[i] = vector<int>(1 << n);
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int mask = 0; mask < (1 << n); ++mask)
      for (vector<int>::iterator cover = c.begin(); cover != c.end(); ++cover)
	dp[i + 1][mask | *cover] |= dp[i][mask];
    if (dp[i + 1][(1 << n) - 1]) {
      printf("%d\n", i + 1);
      break;
    }
  }

  return true;
}

int main() {
  while (solve()) {
  }

  return 0;
}
