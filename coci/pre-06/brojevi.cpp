#include <stdio.h>
#include <conio.h>
struct reza {long int prvi, drugi;} rez[200000];
long int M(long int A, long int B) {
    long int t, br = 1, ost;
    const bool da = true;
    if(B > A) {t = B; B = A; A = t;}
    if(A%B == 0) br = B;
    while(da) {
        ost = A%B;
        A = B;
        B = ost;
        if(ost == 0) 
          break;
        br = ost;
    }
    return br;
}
long int V(long int A, long int B) {
    long int t, a1, b1;
    a1 = A; b1 = B; 
    while(a1 != b1) {
       if(a1 < b1) 
         a1+=A; 
       else if(a1 > b1) 
         b1+=B;
    }
    return a1;
}                              
int main() {
    long int a, b; long int i = 0, j, puta;
    scanf("%ld", &puta);
    for(int l = 0; l < puta; l++) {
      scanf("%ld %ld", &a, &b);
      rez[l].prvi = M(a, b);
      rez[l].drugi = V(a, b);
    }    
    for(int l = 0; l < puta; l++) { 
      printf("%ld ", rez[l].prvi);
      printf("%ld\n", rez[l].drugi);
      getch();
    }    
    
    
            getch();
            return 0;
}            
