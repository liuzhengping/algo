#include <cstdio>
long long int d[100000], t[100000], n, m;
int main() {
    scanf("%lld %lld", &n, &m);
    for(long long int i = 0; i < n; i++) scanf("%d", &d[i]);
    t[0] = 1;
    for(long long int i = 0; i < n; i++) {
        long long int c = d[i];
        for(long long int j = c; j <= m; j++)
          t[j]+=t[j-c];
    }
    /*nway[0] = 1;
    for (int i=0; i<n; i++) {
      int c = d[i];
      for (int j=c; j<=m; j++)
        nway[j] += nway[j-c];
    }*/
    printf("%lld", t[m]);
    scanf("%lld", &t[m]);
    return 0;
}       
        
