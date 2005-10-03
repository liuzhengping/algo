#include <cstdio>
#define MAX 100
long int mat[MAX][MAX], mat2[MAX][MAX], matres[MAX][MAX];
int mnozi(int n) {
  for(int i = 0; i < n; i++) {
          for(int j = 0; j < n; j++) 
              for(int k = 0; k < n; k++) {
                  matres[i][j] += mat[i][k]*mat2[k][j];   }
  }
}    
int main() {
    int m, n;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        scanf("%ld", &mat[i][j]);
        mat2[i][j] = mat[i][j];
      }
    }
    mnozi(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) 
          printf("%5ld", matres[i][j]);
        printf("\n");
    }             
    
     scanf("%d", &n);      
    return 0;
}    
    
