#include <cstdio>
#include <iostream.h>
int polje[101];
int main() {
    int N, P, b = 0, c = 0;
    scanf("%d %d", &P, &N);
    for(int i = 0; i < N; i++) {
        int x; scanf("%d", &x);
        if(i%2) polje[x] = 2;
        else polje[x] = 1;
        int j = x;
        while(polje[++j] != polje[x] && polje[j] && j <= P);
        if(polje[j] == polje[x])
           for(int l = x+1; l < j; l++) polje[l] = 0;
    }
    for(int i = 1; i <= P; i++) {
       if(polje[i] == 1) b++; else if(polje[i] == 2) c++; }
    printf("%d %d", b, c);
    scanf("%d", &c);   
    return 0;
}
    

