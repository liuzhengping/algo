#include <stdio.h>
#include <conio.h>
void sort(int *m, int M) {
    for(int k = 1; k < M; k++) { 
        int br = 0;
        for(int l = k; l >= 0; l--)
            if(l != k && m[l] == m[k]) {
              ++br; break;}
        if(br) {      
          for(int l = k; l >= 0; l--)
              if(l != k && m[l] >= m[k])
                  ++m[l];
        }    
    }    
}          
int main() {
    int M, N, m[100], n[100];
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) scanf("%d", &n[i]);
    for(int i = 0; i < M; i++) scanf("%d", &m[i]);
    sort(m, M);
    sort(n, N);
    for(int k = 1; k <= 3; k++) {
      for(int m1 = M-1; m1 >= 0; m1--)
        if(m[m1] == k) {
          for(int n1 = N-1; n1 >= 0; n1--)  
            if(n[n1] == M-m1) {
                printf("%d\n", n1+1);
                break;
            }    
        }
    }        
    getch();
    return 0;
}    
