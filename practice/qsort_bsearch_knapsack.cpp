#include <cstdio>
#include <algorithm>
using namespace std;
void qs(int *a, int l, int r) {
    if(r >= l) {
        int i, j, v, t;
        v = a[r];
        i = l-1; j = r;
        for(;;) {
            while(a[++i] < v);
            while(a[--j] > v);
            if(j <= i) break;
            swap(a[i], a[j]);
        }
        swap(a[i], a[r]);
        qs(a, l, i-1);
        qs(a, i+1, r);
    }    
}
int bs(int *a, int br, int l, int r) {
    while(l <= r) {
      int j = (l+r)/2;
      if(a[j] == br) return j;
      else if(a[j] > br) r = j-1;
      else l= j+1;
    }
}
void knapsack() {
    int val[50], size[50], cost[50], best[50];
    val[1] = 4; size[1] = 3;
    val[2] = 5; size[2] = 4;
    val[3] = 10; size[3] = 7;
    val[4] = 11; size[4] = 8;
    val[5] = 13; size[5] = 9;
    int M = 17, N = 5;
    for (int k = 0; k < 50; k++) {
        size[k] = 0; best[k] = 0; val[k] = 0; cost[k] = 0;
    }    
    
    for(int j = 1; j <= N; j++) {
      for(int i = 1; i <= M; i++) { 
        if(i >= size[j])
          if(cost[i] < cost[i-size[j]]+val[j]) {
             cost[i] = cost[i-size[j]]+val[j];  
             best[i] = j;
          }
      }
  }        
    printf("%d\n", cost[M]);
    /*int g = M;
    while(g > 0) {
         printf("%d ", best[g]);
         g-=size[best[g]];
     }*/
 }                          
int main() {
    int a[10] = {6,4,2,1,9,6,7,7,3,5}, br;
    qs(a, 0, 9);
    for(int i = 0; i < 10; i++) printf("%2d", a[i]);
    scanf("%d", &br);
    printf("\nBroj je na %d. poziciji.\n", bs(a, br, 0, 9));
    knapsack();
    scanf("%d", &br);
    return 0;
}    
