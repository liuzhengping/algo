#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

char slova[7] = {'I','V','X','L','C','D','M'}; int m;
int vrijednosti[7] = {1, 5, 10, 50, 100, 500, 1000};
class broj {
    public:
        char r_znam;
        int vr, pr_vr;
    void popuni() {        
        for(m = 0; m < 7; m++) {
           if(slova[m] == r_znam) { 
             vr = vrijednosti[m];
             pr_vr = vrijednosti[m];
           }    
        }
    }        
};  
broj a[20];
class broj2 {
    public:
        char r_znam;
        int vr, pr_vr;
    void popuni() {        
        for(m = 0; m < 7; m++) {
           if(slova[m] == r_znam) { 
             vr = vrijednosti[m];
             pr_vr = vrijednosti[m];
           }    
        }
    }        
};
broj2 b[20];  
int main() {
    int i, j, k, max = 0, brojac = 0, mj_max = -1, suma = 0, suma2;
    char upis[20], upis2[20]; int da = 1;
    scanf("%s", &upis);
    for(i = 0; i < strlen(upis); i++) {
        a[i].r_znam = upis[i]; 
        a[i].popuni();
    }
      for(i = strlen(upis); i >= 0; i--) {
          for(j = i-1; a[j].vr < a[i].vr; j--)
            a[j].pr_vr = -a[j].vr;
      }      
    for(i = 0; i < strlen(upis); i++) 
          cout << a[i].pr_vr << "\t";
    for(i = 0; i < strlen(upis); i++) 
        suma+= a[i].pr_vr;
    cout << "[[[[[[[[" << suma << "]]]]]]]";
    cout << "\nUpisite broj: ";
    scanf("%d", &suma2);
    suma2*=2;
    sprintf(upis2, "%d", suma2);
    cout << upis2 << endl;
    /*for(i = 0; i < strlen(upis); i++) 
        b[i].vr = upis2[i] - '0';*/
    j = 0;
    for(i = 6; i >= 0; i--) {    
    while(suma2 > vrijednosti[i]) {
      suma2-= vrijednosti[i];
      b[j++].vr = vrijednosti[i];
    }
    }        
    for(j = 0; j < 10; j++) 
        cout << b[j].vr << "\t";
    cout << suma2;                                           
    getch();
    getch();
    return 0;
}
/*
while(suma2 > 0) {
      if(suma2/1000 > 0) {
          b[i].vr = suma/1000;
          suma-=b[i++].vr*1000;
      }    
      else if(suma2/500 > 0) {
          b[i].vr = suma/500;
          suma-=b[i++].vr*500;
      }
      else if(suma2/100 > 0) {
          b[i].vr = suma/100;
          suma-=b[i++].vr*100;
      }
      else if(suma2/50 > 0) {
          b[i].vr = suma/50;
          suma-=b[i++].vr*50;
      }
      else if(suma2/10 > 0) {
          b[i].vr = suma/10;
          suma-=b[i++].vr*10;
      }
      else if(suma2/5 > 0) {
          b[i].vr = suma/5;
          suma-=b[i++].vr*5;
      }
      else if(suma2/1 > 0) {
          b[i].vr = suma/1;
          suma-=b[i++].vr;
      }
    }  */              
