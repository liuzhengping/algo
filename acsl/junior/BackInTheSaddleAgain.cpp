#include <stdio.h>
#include <iostream.h>
#include <conio.h>
int polje[3][2];
struct koordinate {
    int x; 
    int y;
    void resetiraj() {x = -1; y = -1;}
} ko[2];
bool provjeri(int i2, int m2) {
    if(m2 == 0 && polje[i2][0] >= polje[i2][1] 
       || m2 == 1 && polje[i2][1] >= polje[i2][0])
      return 1;
    return 0;
}        
void poslozi(int *temp) {
  int t;  
  for(int i = 0; i < 2; i++) {
            for(int j = i+1; j < 3; j++) {
                if(temp[j] > temp[i]) {
                    t = temp[i];
                    temp[i] = temp[j];
                    temp[j] = t;
                }
            }
  }
  
}    
int main() {
    int temp1[3]; int br, br_rez, rez[2];
    for(int puta = 1; puta <= 5; puta++) {
        br = 0;
        br_rez = 0;
        for(int h = 0; h < 2; h++)
          ko[h].resetiraj();    
        printf("Line #%d: ", puta);
        for(int k = 0; k < 3; k++) {  
          for(int l = 0; l < 2; l++) 
            scanf("%d", &polje[k][l]);
        }
       for(int m = 0; m < 2; m++) {
        for(int k = 0; k < 3; k++) 
            temp1[k] = polje[k][m];
        poslozi(temp1);
        for(int i = 0; i < 3; i++) {
            if(temp1[0] == polje[i][m] && temp1[0] > temp1[1]) {
              if(provjeri(i,m)) {  
                ko[m].x = m; ko[m].y = i; 
                br++;
              }    
            }
        }
        if(ko[m].x != -1)
          rez[br_rez++] = polje[ko[m].y][ko[m].x];
      }
      printf("Output #%d: ", puta);
      if(br_rez == 1 || rez[0] == rez[1])
        printf("%d", rez[0]);
      else if(br_rez == 2)
        printf("%d and %d", rez[0], rez[1]);
      else
        printf("none");
      printf("\n");      
    }
    getch();
    return 0; 
}                                                      
