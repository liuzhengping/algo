#include <cstdio>
int main() {
    int n, t, r, suma = 0, rj = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &t);
        suma += t;
        if(suma < rj) rj = suma;
    }
    rj *= -1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &t);
        if(t > rj && t > 0) printf("1\n"); else printf("0\n");
    
    }
    scanf("%d", &n);
    return 0;   
}         
        
