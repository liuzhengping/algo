#include <stdio.h>
#include <conio.h>
int main() {
    int j, i, N, M, cost[50], size[50], best[50], val[50];
    for (int k = 0; k < 50; k++) {
        size[k] = 0; best[k] = 0; val[k] = 0; cost[k] = 0;
    }
    val[1] = 1; size[1] = 1;
    val[2] = 1; size[2] = 2;
    val[3] = 1; size[3] = 5;
    
    M = 10; N = 3;
    
    for(j = 1; j <= N; j++) {
        for(i = 1; i <= M; i++) {
            if(i >= size[j]+size[i-size[j]])
              if(cost[i] < cost[i-size[j]]+val[j]) {
                  cost[i] = cost[i-size[j]] + val[j];
                  best[i] = j;
              }
        }
        printf("%d: %d\n", j, best[M]);
    }
    printf("evo ga:\n");
    int g = M;
    while (g > 0) {
        printf("%d\n", best[g]);
        g-=size[best[g]];
        getch();
    } 
    printf("\n\n%d %d %d", cost[8], cost[9], cost[10]);    
    getch();
    return 0;
}    
                    
