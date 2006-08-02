#include <cstdio>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#define MAX 102
using namespace std;
int n, m;
int mat[MAX][MAX];
const int inf = 100000;
void init() {
    for(int i = 0; i < MAX; i++)
      for(int j = 0; j < MAX; j++) ma[i][j] = inf;
}
int bfs(int a, int b) {
    queue<int> q;
    vector<int> distA(n, inf);
    vector<int> distB(n, inf); 
    distA[a] = 0;
    distB[b] = 0;
    for(q.push(a); !q.empty(); q.pop()) {
        int x = q.front();
        for(int i = 1; i < n; i++) 
          if(mat[x][i]) {
              distA[i] = distA[x]+1;
              q.push(i);
          }    
    }
    for(q.push(b); !q.empty(); q.pop()) {
        int x = q.front();
        for(int i = 1; i < n; i++)
          if(mat[x][i]) {
              distB[i] = distB[x]+1;
              if(distB[i] < distA[i]) q.push(i);
          }    
    }           
    return 1;
}       
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        mat[a][b] = 1;
    } 
    scanf("\n");
    return 0;
}    
