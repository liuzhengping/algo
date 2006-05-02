#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
int rek(int a, int b, const int c, int br) {
    int sol = 999;
    if(a == c || b == c) return br;
    if(br > 10) return 1000;
    sol = min(sol, rek(-a,b,c,br+1));
    sol = min(sol, rek(a,-b,c,br+1));
    sol = min(sol, rek(a+b,b,c,br+1));
    sol = min(sol, rek(a,a+b,c,br+1));
    return sol;
}    
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int sol = rek(a,b,c,0); if(sol == 999) printf("-1"); else printf("%d", sol);
    scanf("\n");
    return 0;
}    
