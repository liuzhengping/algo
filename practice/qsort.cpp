#include <cstdio>
int niz[15] = {1,7,4,8,4,18,14,2,3,12,14,11,10,15,1};
void qs(int l, int r, int *a) {
    if(l < r) {
      int j, i, t, v;
      v = a[r]; j = r; i = l-1;
      for(;;) {
          while(a[++i] < v);
          while(a[--j] > v);
          if(j <= i) break;
          t = a[i]; a[i] = a[j]; a[j] = t;
      }
      t = a[i]; a[i] = a[r]; a[r] = t;
      qs(l, i-1, a);
      qs(i+1, r, a);
    }
}             
int main() {
    qs(1, 14, niz);
    for(int i = 0; i < 15; i++) printf("%d ", niz[i]);
    int tmp; scanf("%d", &tmp);
    return 0;
}    
    
    
