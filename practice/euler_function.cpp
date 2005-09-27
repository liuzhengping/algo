#include <stdio.h>
#include <conio.h>
#include <time.h>
long int mjera(long int x, long int y) {
    long int t;
    bool da = 1;
    while(da) {
      t = x % y;
      if(t == 0) break;
      x -= (x % y);
      y = t;
    }
    return y;     
}    
int main() {
    
    long int n, m, br = 0;
    scanf("%ld", &n);
    double c = clock();
    for(int i = 1; i <= n; i++) 
        if(mjera(n, i) == 1) br++;  
    printf("%ld", br);
    c = (clock() - c)/1000;
    printf("\n%lf s", c);   
    getch();
    return 0;
}    
