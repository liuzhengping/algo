#include <cstdio>
#define MAX 100001
int kol[MAX], dist[MAX], n;
int probaj(int x) {
    int uviz = 0;
    for(int i = 0; i < n-1; i++) {
        if(kol[i]+uviz < x)
          uviz += (kol[i]-x) - (dist[i+1]-dist[i]);
        else {
          uviz+=(kol[i]-x)-(dist[i+1]-dist[i]);
          if(uviz < 0) uviz = 0;
        }
    }
    if(kol[n-1]+uviz >= x) return 1;
    return 0;        
} 

int main() {
    int maxkol = -1; 
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &dist[i], &kol[i]);
        maxkol >?= kol[i]; 
    }
    int left = 1, right = maxkol, x;
    while(left < right) {
        x = (left+right+1)/2;
        if(probaj(x))
          left = x;
        else
          right = x-1;
    }
    printf("%d", left);        
    scanf("\n");
    return 0;
}    
