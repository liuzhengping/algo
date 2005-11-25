#include <cstdio>
int m, n, st, en;     
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

int main() {
    
    scanf("%d %d", &m, &n);
    for(int i = 0; i < n; i++) {
        int a, b, c; scanf("%d %d %d" , &a, &b, &c);
        polje[--a][--b] = c;
    }
    scanf("%d %d", &st, &en);
    for(int i = 0; i < m; i++) p.niz[i] = polje[st][i];
    int v = p.mini(); 
    for(;v != -1; v = p.mini()) {
        p.da[v] = true; printf("(%d)", v);
        for(int i = 0; i< m; i++) 
            if(polje[v][i])
              if(!p.niz[i] || p.niz[i] > p.niz[v]+polje[v][i])
                p.niz[i] = p.niz[v]+polje[v][i];
    }    
    for(int i = 0; i< m; i++) printf("%2d", p.niz[i]);        
        
    int tmp; scanf("%d", &tmp);
    return 0;
}
/*6 9
1 2 3
1 5 2
2 3 1
3 4 4
4 2 2
4 1 4
4 6 5
5 3 2
6 5 1
3 4*/    
