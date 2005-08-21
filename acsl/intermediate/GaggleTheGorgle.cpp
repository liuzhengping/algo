#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <math.h>
int n1, n2, n3;
void radi(int N1, int N2, int N3) {
    n1 = abs(N2-N3);
    n2 = abs(N1-N3);
    n3 = abs(N1-N2);
}    
int main() {
    for(int puta = 1; puta <=5; puta++) {
      int count = 0, da = 1;
      printf("Line #%d: ", puta);
      scanf("%d %d %d", &n1, &n2, &n3);
      while(da) {
          if(n1 == n2 || n2 == n3 || n1 == n3) break;
          count++;
          radi(n1, n2, n3);
      }    
      printf("\nOutput #%d: %d\n", puta, count);
    }    
    getch();
}    
    
    
    
