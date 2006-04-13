#include <cstdio>
int polje[100][100];
int main() {
    int m, n, sol, max = -32768;
    scanf("%d%d", &m, &n);
    for(int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        polje[--a][--b] = 1;
    }
    for(int x = 0; x < m; x++)
      for(int j = 0; j < m; j++)
        if(polje[x][j])
          for(int y = 0; y < m; y++)
            if(polje[j][y])
              if(!polje[x][y] || polje[x][y] > polje[x][j]+polje[j][y])
                polje[x][y] = 1;
    for(int i = 0; i < m; i++) {
      int br = 0;
      for(int j = 0; j < m; j++)
        if(polje[i][j]) br++;
      if(br > max) {sol = br; max = br;}
    }  
    printf("%d", sol);  
    scanf("\n");  
    return 0;
}    
