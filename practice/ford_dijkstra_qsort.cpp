#include <cstdio>
int t[1000];
void qs(int *a, int l, int r) {
    int v, i, j, t;
    if(r > l) {
        v = a[r]; i = l-1; j = r;
        for(;;) {
            while(a[++i] < v);
            while(a[--j] > v);
            if(j <= i) break;
            t = a[i]; a[i] = a[j]; a[j] = t;
        }
        t = a[i]; a[i] = a[r]; a[r] = t;        
        qs(a, l, i-1);
        qs(a, i+1, r);
    }    
}
void print(int x) {
    if(t[x*2+1] != -1) print(x*2+1);
    printf("(%d)", t[x]);
    if(t[x*2+2] != -1) print(x*2+2);
}    
void b(int *a) {
    for(int i = 0; i < 1000; i++) t[i] = -1;
    t[0] = a[0];
    for(int i = 1; i < 10; i++) {
        int node = 0, x = a[i];
        while(t[node] != -1) {
            if(x <= t[node]) node=node*2+1;
            else node=node*2+2;
        }
        t[node] = x;    
    }
    print(0);    
    
}
void floyd {
    for(int j = 0; j < m; j++)
       for(int x = 0; x < m; x++)
          if(p[x][j])
            for(int y = 0; y < m; y++)
              if(p[j][y])
                if(!p[x][y] || p[x][y] > p[x][j]+p[j][y];
                  p[x][y] = p[x][j]+p[j][y];
}
struct d {
    int niz[100];
    bool da[100];
    int mini() {
        int mi = 32767; int val = -1;
        for(int i = 0; i < m; i++)
          if(!da[i] && niz[i] && niz[i] < mi) {
              mi = niz[i]; val = i;
          }     
        return val;
    }
} p; 
int polje[101][101];
       
void dijkstra {
    for(int i = 0; i < m; i++) p.niz[i] = polje[st][i];    
    int v = p.mini(); 
    for(;v != -1; v = p.mini()) {
        p.da[v] = true;
        for(int i = 0; i < m; i++) {
            if(polje[v][i])
              if(!niz[i] || niz[i] > niz[v] + polje[v][i])
                niz[i] = niz[v] + polje[v][i];
    }       
}
struct edge {int st; int dest; int year;};
vector<edge> v;      
void ford() {
    int N, n, m;
    
    
        scanf("%d %d", &n, &m);
        v.resize(n);
        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &v[i].st, &v[i].dest, &v[i].year);
            v[i].st--; v[i].dest--; v[i].year;
        }
        vector<long> dist(n, inf);
        dist[0] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(dist[v[j].dest] > dist[v[j].st] + v[j].year)
                  dist[v[j].dest] = dist[v[j].st] + v[j].year
            }
        }
        for(int j = 0; j < m; j++) {
                if(dist[v[j].dest] > dist[v[j].st] + v[j].year) {
                  printf("not possible"); return;
        }
     printf("possible");
}
void knapsack() {
    nt val[50], size[50], cost[50], best[50];
    val[1] = 4; size[1] = 3;
    val[2] = 5; size[2] = 4;
    val[3] = 10; size[3] = 7;
    val[4] = 11; size[4] = 8;
    val[5] = 13; size[5] = 9;
    int M = 17, N = 5;
    for (int k = 0; k < 50; k++) {
        size[k] = 0; best[k] = 0; val[k] = 0; cost[k] = 0;
    } 
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(i >= size[j]) {
                if(cost[i] < cost[i-size[j]]+val[j]) {
                cost[i] < cost[i-size[j]]+val[j]
                best[i] = j;
                }
             }
         }
     }
     int g = M;
     while(g > 0) {
         printf("%d", best[g]);
         g-=size[best[g]];
     }                    
                
                   
}            
int main() {
    int a[10] = {6,4,2,1,9,6,7,7,3,5}, br;
    //qs(a, 0, 9);
    b(a); dfs();
    for(int i = 0; i < 10; i++) printf("%2d", a[i]);
    scanf("%d", &a[0]);
    return 0;    
}    
