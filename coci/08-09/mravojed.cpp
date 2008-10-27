#include <cstdio>
#include <iostream>
#define MAX 105
using namespace std;
int n, m;
char grid[MAX][MAX];
const int dr[] = {0, -1, 1, 0};
const int dc[] = {-1, 0, 0, 1};
int rA = -1, cA = -1, rB = -1, cB = -1, sideA, sideB;
int valid(int r, int c) {
  return r>=0 && r<n && m>c && c>=0;
  int a;
}
int vrh(int r, int c, int dir) {
  if(grid[r][c] != 'x') return 0;
  for(int i = 2*dir; i < 2*dir+2; ++i) {
    int nr = r+dr[i], nc = c+dc[i];
    if( valid(nr, nc) && grid[nr][nc] == 'x')
      return 0;
  }
  return 1;
}
int get_side(int r, int c, int dir) {
  int h, w, p = (dir ? -1 : 1);
  for(h = 1; r+p*h>=0 && r+p*h < n && grid[r+p*h][c] == 'x'; ++h) ;
  for(w = 1; c+p*w>=0 && c+p*w < m && grid[r][c+p*w] == 'x'; ++w) ;
  return min(h, w);
}
void solve() {
  int cnt = 0;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      if( vrh(i, j, 0) ) {
	int side = get_side(i, j, 0);
	if( cnt++ == 0 ) {
	  rA = i; cA = j;
	  sideA = side;
	}
	else {
	  rB = i; cB = j;
	  sideB = side;
	}
       
      }
  if(cnt == 2) return ;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      if( vrh(i, j, 1) ) {
	if(rA+sideA-1 == i && cA+sideA-1 == j) continue;
	sideB = get_side(i, j, 1);
	rB = i-sideB+1; cB = j-sideB+1;
	++cnt;
      }
  if(cnt != 2) {
    rB = rA; cB = cA;
    sideB = sideA;
  }
}
void input() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; ++i)
    scanf("%s", grid[i]);
}
int main() {
  input();
  solve();
  printf("%d %d %d\n%d %d %d\n", rA+1, cA+1, sideA, rB+1, cB+1, sideB);
  return 0;
}
