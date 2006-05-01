#include <cstdio>
#include <cstdlib>
int n, m, soba[101];
int main() {
    scanf("%d %d", &n, &m);
    for(int puta = 0; puta < m; puta++) {
        int x;
        scanf("%d", &x);
        for(int i = 0; i < n && !(!x || x == 1); i++) 
          if(!soba[i]) { 
            soba[i] = 2; x-=2;
          } 
        for(int i = 0; i < n && x; i++)
          if(!soba[i]) {
            soba[i]++; x--; 
          }
        for(int i = 0; i < n && x; i++)
          if(soba[i] < 2) {
            soba[i]++; x--; 
          }          
    } 
    for(int i = 0; i < n; i++) printf("%d\n", soba[i]); 
    scanf("\n");
}    
