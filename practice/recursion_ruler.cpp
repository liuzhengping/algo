#include <stdio.h>
#include <conio.h>
int a[1000];
void rule(int l, int r, int h) {
    int m = (l+r)/2;
    if(h > 0) {
        printf("%d (%d)\n", a[m], h);
        rule(l, m, h-1);
        rule(m, r, h-1);
    }
}        
int main() {
    for(int i = 0; i < 1000; i++) a[i] = i;
    rule(0, 64, 6);
    getch();
    return 0;
}    
    
    
