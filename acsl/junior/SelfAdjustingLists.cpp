#include <iostream.h>
#include <stdio.h>
#include <conio.h>
int polje[10] = {81,20,37,15,57,19,21,93,92,45};
int temp[20];
int main() {
    int i = 0, j, k2, k, t, puta;
    for(j = 0; j < 20; j++)
      temp[j] = -1;
   for(puta = 1; puta <= 5; puta++) {
    printf("Line #%d: ", puta);      
    do {
        scanf("%d", &temp[i]);
    } while(temp[i++] != 0);
    for(j = 0; j < i; j++) {
        for(k = 0; k < 20; k++) {
            if(polje[k] == temp[j] && temp[j] > 1) {
              t = polje[k]; 
              for(k2 = k; k2 < 19; k2++)
                polje[k2] = polje[k2+1];
              polje[19] = t;  
            }
        }
    }
    printf("\nOutput #%d: ", puta);           
    for(i = 0; i < 20; i++) {
        if(polje[i] != 0 && polje[i] != -1)
          cout << polje[i] << " ";
    }
    printf("\n");
  }                      
    getch();
    return 0;
}          
