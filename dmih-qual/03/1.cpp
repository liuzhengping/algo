#include <cstdio>
#include <iostream>
int main() {
    int n, h, min, tt, tt2, suma, suma2, rez = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        suma = 0; suma2 = 0;
        scanf("%d:%d %d", &h, &min, &tt);
        suma = min+h*60; tt2 = 0;
        if(suma >= 19*60 || suma < 7*60) {
            if(suma+tt >= 7*60 && h >= 0 && h < 8) {
              tt2 = suma+tt-7*60;
              tt-=tt2;
            }
            rez+=(tt*5)+(tt2*10);  
        }
        else {
            if(suma+tt >= 19*60) {
               tt2 = suma+tt-19*60;
               tt-=tt2;
            }
            rez+=(tt*10)+(tt2*5);    
        }  
    }         
    printf("%d", rez);
    scanf("%d", &min);        
    return 0;
}    
