#include <stdio.h>
#include <conio.h>
int main() {
    double a, b, temp;
    a = 1; b = 1;
    while(!kbhit()) {
        printf("%.0lf\n%.0lf\n", a, b);
        a = a+b;
        b+= a;
        getch();  
    }    
    getch();
    getch();
    return 0;
}    
    
    
