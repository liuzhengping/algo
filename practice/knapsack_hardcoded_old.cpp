#include <cstdio>
int main() {
    int w, i, C[100][100], val[100], size[100], best[100];
    val[1] = 4; size[1] = 3;
    val[2] = 5; size[2] = 4;
    val[3] = 10; size[3] = 7;
    val[4] = 11; size[4] = 8;
    val[5] = 13; size[5] = 9;
    int N = 5, MW = 17; 
    for (i=0;i<=N ;i++) C[i][0] = 0;
    for (w=0;w<=MW;w++) C[0][w] = 0;
    for (w=0;w<=MW;w++) best[w]= 0;

    for (i=1;i<=N;i++) {
      for (w=1;w<=MW;w++) {
        if (size[i] > w)
          C[i][w] = C[i-1][w];
        else {
          if(C[i-1][w] > C[i-1][w-size[i]]+val[i])
            C[i][w] = C[i-1][w];
          else C[i][w] = C[i-1][w-size[i]]+val[i];
          best[w] = i;
         }    
      }    
    } 
 

    printf("%d", C[N][MW]); 
    scanf("%d", &MW);
    return 0;
}
