#include <cstdio>
#include <iostream>
#define MAX 10
using namespace std;
int n;
int grid[MAX][MAX], sum[MAX][MAX], dp[MAX][MAX][MAX][MAX];
const int inf = 1000000000;
int get_sum(int r1, int c1, int r2, int  c2) {
  int a = r1 ? sum[r1-1][c2] : 0;
  int b = c1 ? sum[r2][c1-1] : 0;
  int c = (r1 && c1) ? sum[r1-1][c1-1] : 0;
  return sum[r2][c2]-a-b+c;
}  
int rec(int r1, int c1, int r2, int  c2) {
  if(r2-r1 == 0 && c2-c1 == 0) return !grid[r1][c1];
  if(r2-r1 == c2-c1 && get_sum(r1, c1, r2, c2) == 0)
    return 1;  
  int &ret = dp[r1][c1][r2][c2];
  if(ret != -1) return ret;
  ret = inf;
  for(int r = r1; r < r2; ++r)
    ret <?= rec(r1, c1, r, c2) + rec(r+1, c1, r2, c2);
  for(int c = c1; c < c2; ++c)
    ret <?= rec(r1, c1, r2, c) + rec(r1, c+1, r2, c2);
  return ret;
}
void precompute() {
  sum[0][0] = grid[0][0];
  for(int i = 1; i < n; ++i) {
    sum[i][0] = sum[i-1][0] + grid[i][0];
    sum[0][i] = sum[0][i-1] + grid[0][i];
  }
  for(int i = 1; i < n; ++i)
    for(int j = 1; j < n; ++j)
      sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + grid[i][j];
}
void input() {
  static char s[MAX+1];
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%s", &s);
    for(int j = 0; j < n; ++j)
      if(s[j] == 'x')
        grid[i][j] = 1;
  }
}
int main() {
  memset(dp, -1, sizeof dp);
  input();
  precompute();
  printf("%d\n", rec(0, 0, n-1, n-1));
  return 0;
}
