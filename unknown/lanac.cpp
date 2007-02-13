#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;
#define MAX 21
typedef list<int>::iterator Li;
int n, m, graf[MAX][MAX], degin[MAX], degout[MAX], st, en;
vector< list<int> > adj;
int euler(int x, int k) {
    if(k == m) {printf("%d", x); return 1; }
    for(Li it = adj[x].begin(); it != adj[x].end(); ++it) {
      if(graf[x][*it] && (degout[*it] || k+1 == n)) {
        --degout[x]; --degin[*it]; graf[x][*it] = 0;
        if( euler(*it, k+1) ) {printf("%d", x); return 1; }
        ++degout[x]; ++degin[*it]; graf[x][*it] = 1;
      }    
    }
    return 0;    
}    
int main() {
    scanf("%d %d", &n, &m); adj.resize(n+1);
    for(int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        ++degout[a]; ++degin[b];
        adj[a].push_back(b);
        graf[a][b] = 1;
    } 
    int maxin = 0, maxout = 0;
    bool nemoguce = 0;
    for(int i = 0; i <= n; ++i) {
        if(degout[i]-degin[i] > 1) {nemoguce = 1; break;}
        else if(degin[i]-degout[i] > 1) {nemoguce = 1; break;}
        else if(degout[i]-degin[i] == 1) {
            if(st > 0) {nemoguce = 1; break;}
            st = i;
        } 
        else if(degin[i]-degout[i] == 1) {
            if(en > 0) {nemoguce = 1; break;}
            en = i;
        }       
    }   
    if(nemoguce) printf("ne mogu napraviti lanac");
    else {
        if(!st) 
            for(int i = 1; i <=n; ++i) {if(i != en) {st = i; break;}}
        if(!en)
            for(int i = 1; i <=n; ++i) {if(i != st) {en = i; break;} }   
        printf("(%d -> %d)\n", st, en);
        euler(st, 1);
    }    
    
    scanf("\n");
    return 0;
}
/*
4 5
1 3
3 2
2 1
1 4
4 3
*/    
