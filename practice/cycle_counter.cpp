#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100
vector< vector<int> > adj;
int n, m, val[MAX];
int dfs(int x, int dad) {
    val[x] = 1;
    int ret = 0;
    for(int i = 0; i < adj[x].size(); ++i) {
      if(val[adj[x][i]]) {
          if(dad != adj[x][i]) {printf("%d->%d\n", x+1, adj[x][i]+1);++ret;}
      }    
      else ret += dfs(adj[x][i], x);
    }
    return ret;    
}    
int main() {
    n = 5;
    printf("Upisuj edgeve (directed), za kraj metni 0 0:\n");
    for(int a, b;;) {
        scanf("%d %d", &a, &b); if(!a) break;
        --a; --b; m >?= max(a, b);
       if(adj.size() <= m) adj.resize(m+1);
        adj[a].push_back(b);
    }
    int sol = 0;
    for(int i = 0; i < n; ++i) sol+= dfs(i, -1);
    printf("Broj krugova = %d", sol);   
    scanf("\n");
    return 0;
}    
/*
1 2
1 4
2 1
2 4
2 5
3 2
4 1
4 3
5 1
5 4

1 2
1 5
1 6
2 2
2 3
2 4
3 4
3 5
3 6
4 1
4 2
4 5
5 4
6 5
6 3
*/
