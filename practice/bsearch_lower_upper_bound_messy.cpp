#include <cstdio>
int niz[10] = {1,2,4,4,5,7,8,8,8,10};
int ub(int l, int r, int v) {
    int best = -1;
    while(l <= r) {
          int x = (l+r)/2;
          //if(v == niz[x]) return x;
          if(v < niz[x]) r = x-1;
          else {
              best = x;
              if(v == niz[x])  best++;
              l = x+1;
          }    
    }
    return best;        
}
int lb(int l, int r, int v) {
    int best = -1;
    while(l <= r) {
          int x = (l+r)/2;
          //if(v == niz[x]) return x;
          if(v > niz[x]) l = x+1;
          else {
              best = x;
              if(v == niz[x])  best--;
              r = x-1;
          }    
    }
    return best;        
}        
int main() {
    for(;;) {
      int tmp; scanf("%D", &tmp);
      if(tmp == -1) break;
      else printf("%d %d", ub(0, 9, tmp), lb(0, 9, tmp));
    }     
    return 0;
}    
    
