#include <stdio.h>
#include <iostream.h>
#include <conio.h>
int polje[8][8];
class pento {
    public:
    int x, y; char c;
    void umetni();
};
pento pentominoes[10];
void pento::umetni() {
  polje[--y][--x] = 1;  
  if(c == 'A' || c == 'a') {
    polje[y-1][x] = 1; polje[y-2][x] = 1; polje[y-2][x+1] = 1; polje[y-2][x+2]= 1;
  }   
  else if(c == 'B' || c == 'b') {
    polje[y-1][x] = 1; polje[y-2][x] = 1; polje[y][x+1] = 1; polje[y-1][x+1] = 1;
  }
  else if(c == 'C' || c == 'c') {
    polje[y+1][x] = 1; polje[y][x-1] = 1; polje[y][x-2] = 1; polje[y][x-3] = 1;
  }        
}        
int main() {
    int N, j, i, puta, brojac = 0;
    
   for(puta = 1; puta <=5; puta++) { 
    printf("Line #%d: ", puta);
    scanf("%d", &N);
    for(j = 0; j < N; j++)
        cin >> pentominoes[j].c >> pentominoes[j].x >> pentominoes[j].y;
    for(j = 0; j < N; j++)
      pentominoes[j].umetni();
    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++) {
            if(polje[i][j] == 1) ++brojac; 
        }
    }
    printf("Output #%d: %d\n", puta, brojac);
   }                  
    while(!kbhit());
    return 0;
}      
    
