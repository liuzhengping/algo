#include <stdio.h>
#include <conio.h>
int main() {
    long long int t[5001]; int d[5001], n, m;
    scanf("%d %d", &n, &m);
    t[0] = 1;
    for(int i = 1; i <= n; i++) t[i] = 0;
    for(int i = 0; i < m; i++) scanf("%d", &d[i]);
    for(int i = 1; i <= n; i++)
      for(int j = 0; j < m; j++)
        if(i >= d[j])
          t[i] += t[i-d[j]];
    printf("%lld", t[n]);
    getch();
}    

