#include <cstdio>

int main() {
  int sum= 0, s, min;
  int p[3][3];
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++){
        scanf("%d", &p[i][j]);
        sum+=p[i][j];
    }  
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      for(int k = 0; k < 3; k++){
        s = sum;
        if (i == j || i == k || j == k) continue;
        s-=p[0][i];
        s-=p[1][j];
        s-=p[2][k];
        min <?= s;
      }
  
  
  printf("%d", min);
  scanf("\n");
  
  
  return 0;
}
