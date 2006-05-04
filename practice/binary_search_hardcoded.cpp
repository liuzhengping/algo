#include <cstdio>
int niz[15] = {1, 3, 4, 5, 6, 8, 8, 8, 8, 14, 17, 21, 76, 77, 78};
int main() {
    int temp;
    for(;;) {
    int a;
    scanf("%d", &a);
    int l = 0, r = 14, x, best = 100;
    while(r >= l) {
        x = (l+r)/2;
        if(niz[x] == a) {
          if(x < best) best = x;
        }
        if(a < niz[x]) r = x-1; else l = x+1;
    }
    printf("\nnadjeno na %d. mjestu.\n", best+1);    
    }    
    scanf("%d", &temp);
    return 0;
}    
