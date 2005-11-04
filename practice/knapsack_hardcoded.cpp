#include <stdio.h>
#include <conio.h>
int main() {
    int j, i, N, M, cost[50], size[50], best[50], val[50];
    for (int k = 0; k < 50; k++) {
        size[k] = 0; best[k] = 0; val[k] = 0; cost[k] = 0;
    }
    val[1] = 4; size[1] = 3;
    val[2] = 5; size[2] = 4;
    val[3] = 10; size[3] = 7;
    val[4] = 11; size[4] = 8;
    val[5] = 13; size[5] = 9;
    M = 17; N = 5;
    
    for(j = 1; j <= N; j++) {
        for(i = 1; i <= M; i++) {
            if(i >= size[j])
              if(cost[i] < cost[i-size[j]]+val[j]) {
                  cost[i] = cost[i-size[j]] + val[j];
                  best[i] = j;
              }
        }
        printf("%d: %d\n", j, best[M]);
    }
    printf("evo ga: %d\n", cost[M]);
    int g = M;
    while (g > 0) {
        printf("%d\n", best[g]);
        g-=size[best[g]];
        getch();
    } 
    printf("\n\n%d", cost[17]);    
    getch();
    return 0;
}    
                    
