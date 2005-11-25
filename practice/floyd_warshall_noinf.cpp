#include <cstdio>
#include <iostream.h>
int polje[101][101];
int main() {
    int m, n, st, en;
    scanf("%d %d", &m, &n);
    for(int i = 0; i < n; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        polje[--a][--b] = c;
    }
    for(int j = 0; j < m; j++)
      for(int x = 0; x < m; x++)
        if(polje[x][j])
          for(int y = 0; y < m; y++)
            if(polje[j][y])
              if(!polje[x][y] || polje[x][y] > polje[x][j] +polje[j][y])
              polje[x][y] = polje[x][j]+polje[j][y];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j< m; j++) printf("%4d", polje[i][j]);
        printf("\n");
    }                  
    int tmp; scanf("%d", &tmp);
    return 0;
}    
