#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#define MAX 7
using namespace std;
int n, adj[MAX][MAX]; 
int dfs(int x) {
  int ret = 0;
  for(int i = 0; i < MAX; ++i) {
    if(!adj[x][i]) continue;
    --adj[x][i];
    --adj[i][x];
    ret >?= dfs(i) + 1;
    ++adj[x][i];
    ++adj[i][x];
  }
  return ret;  
}  
int solve() {
  //brute force ftw
  int ret = 0;
  for(int i = 0; i < MAX; ++i)
    ret >?= dfs(i);
  return ret;
}   
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    ++adj[a][b];
    ++adj[b][a];
  }
  
  printf("%d", solve() );  

  return 0;
}


