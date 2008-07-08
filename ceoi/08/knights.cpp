#include <cstdio>
#include <iostream>
#define MAX 150
using namespace std;
int dp[MAX][MAX], n, m;
int dr[] = {1, -1, -2, -2};
int dc[] = {-2, -2, -1, 1};
int greedy(int r, int c) {
  if(n == 1 || m == 1) return 0;
  return ! (r%4 < 2 && c%4 < 2);
}
bool valid(int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m;
}
int rec(int r, int c) {
  int &ret = dp[r][c];
  if(ret != -1) return ret;
  ret = 1;
  int ok = 0;
  for(int i = 0; i < 4; ++i) {
    int nr = r +dr[i], nc = c + dc[i];
    if( valid(nr, nc) ) {
      ret &= rec( nr, nc );
      ok = 1;
    }
  }
  ret ^= 1;
  return ret; 
}
int main() {
  scanf("%d%d", &n, &m);
  memset(dp, -1, sizeof(dp));
  for(int i = 0; i < n; ++i, printf("\n"))
    for(int j = 0; j < m; ++j)
      printf("%c", (greedy(i, j) ? 'P' : 'N') );
  return 0;
}
