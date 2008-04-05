#include <cstdio>
#include <iostream>
using namespace std;
const int dc[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int dr[] = {0, 1, 0, -1, -1, 1, 1, -1};
string s;
int bio[3][3];
char grid[5][5], buff[11];
int valid(int r, int c) {
  return r >= 0 && r < 3 && c >= 0 && c < 3;
}  
int dfs(int r, int c, int d) {
  if(d == 0) {
    if(s[d] == grid[r][c]) return 1;
    return 0;
  }  
  if(s[d] != grid[r][c]) return 0;
  for(int i = 0; i < 8; ++i) {
    int nr = r+dr[i], nc = c+dc[i];
    if( !valid(nr, nc) || bio[nr][nc]) continue;
    bio[nr][nc] = 1;
    if( dfs(nr, nc, d-1) ) return 1;
    bio[nr][nc] = 0;
  } 
  return 0;   
}  
int ima(string s) {
  ::s = s;
  for(int i = 0; i < 3; ++i)
    for(int j = 0; j < 3; ++j) {
      memset(bio, 0, sizeof bio);
      bio[i][j] = 1;
      if( dfs(i, j, s.size()-1) )
        return 1;
    }  
  return 0;
}  
void solve() {
}  
int main() {
  int n, sol = 0;
  for(int i = 0; i < 3; ++i)
   scanf("%s", &grid[i]);
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%s", &buff);
    if( ima(buff) ) ++sol;
  }  
  printf("%d\n", sol);

  return 0;
}


