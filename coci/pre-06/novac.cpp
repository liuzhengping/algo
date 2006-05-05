#include <stdio.h>
#include <conio.h>
int max[1000];
int main() {
    int val[11] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
    max[0] = 1;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < 11; i++) {
      for(int j = val[i]; j <= n; j++)
        max[j] += max[j-val[i]];
    }
    printf("%d", max[n]);
    scanf("%d");
    return 0;
}        
