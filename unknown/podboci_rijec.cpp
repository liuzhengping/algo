#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() {
    char str[41]; bool da = 0;
    scanf("%s", str);
    int suma = 0, br = 0, rez = 0, best[41][2];
    for(int i = 0; i < strlen(str); i++) {
      suma+= (str[i] - 96); best[i][0] = 500; best[i][1] = 0;
    //if(suma % 2 == 0) {
    printf("---%d---\n", suma);
    for(int j = 0; j < strlen(str) && !da; j++) {
      for(int i = 0; i < strlen(str); i++) {
          if(i != j || j == 0) 
            br+= str[i] -96;
            int a = (j != 0) ? (str[i]-96) : 0;
            int temp = (abs(br-( (suma-a) - br)));
            if(temp < best[i][0]) best[i][0] = temp;
             
             rez = i+1;
             if(a > 0) best[i][1] = 0;
             else
               best[i][1] = 1;
             break;
           
              
      }
      //printf("[%d]", br);
      br = 0;
    }
    //printf("%d", rez);
    getch();
    return 0;
}    
