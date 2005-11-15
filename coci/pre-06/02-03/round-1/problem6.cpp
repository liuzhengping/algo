#include <cstdio>
#include <iostream.h>
#define MAX 101
using namespace std;
int m, n, a, b, c, d; long int polje[MAX][MAX];

    
int main() {
    long int len_a, len_c, min = 20000000;
    scanf("%d %d", &m, &n);
    scanf("%d %d %d %d", &a, &b, &c, &d); a--; b--; c--; d--;
    for(int i = 0; i < n; i++) {
        int t, k, l; scanf("%d %d %d", &t, &k, &l); t--; k--;
        polje[t][k] = l; polje[k][t] = l;
    }
    for(int j = 0; j < m; j++)
      for(int x = 0; x < m; x++)
        if(polje[x][j])
          for(int y = 0; y < m; y++)
            if(polje[j][y])
              if(!polje[x][y] || polje[x][y] > polje[x][j]+polje[j][y])
                 polje[x][y] = polje[x][j]+polje[j][y];
    len_a = polje[a][b];
    len_c = polje[c][d];   
    for(int i = 0; i < m; i++) 
        if(polje[a][i] && polje[i][b] && polje[c][i] && polje[i][d])
          if(polje[a][i]+polje[i][b] == len_a &&
             polje[c][i]+polje[i][d] == len_c &&
             polje[a][i] == polje[c][i])
             if(polje[a][i] < min) min = polje[a][i]; 
    min = (min < 20000000) ? min : -1;
    printf("%ld", min);  
    int tmp; scanf("%d", &tmp);
    return 0;
}    
