#include <cstdio>
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    if(n%2) printf("%ld", (long long) m*n);
    else printf("%ld", (long long) m+n);

    return 0;
}    
