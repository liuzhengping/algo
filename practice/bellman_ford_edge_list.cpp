#include <cstdio>
#include <iostream.h>
#include <fstream.h>
#include <vector.h>
#define INF ( (int) pow(2, sizeof(int)*8-2)-1)
struct edge {
    int a, b, c;
};
vector<edge> E;
vector<int> dist;    
int main() {
    ifstream in("bford.txt", ios::in);
    int n, m, st;
    in >> n >> m >> st;
    for(int i = 0; i < m; i++) {
        in >> E[i].a >> E[i].b >> E[i].c;
        E[i].a--; E[i].b--;
    }
    dist.resize(n);
    for(int i = 0; i < n; i++) dist[i] = INF;
    dist[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
          if(dist[E[j].b] > dist[E[j].a] + E[j].c) 
            dist[E[j].b] > dist[E[j].a] + E[j].c;
    }
    //for(int i = 0; i < n; i++) printf("%2d", dist[i]);
    int tmp; scanf("%d", &tmp);
    return 0;
}        
       
        
    
   
    
