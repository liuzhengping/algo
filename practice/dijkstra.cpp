#include <stdio.h>
#include <fstream.h>
#include <string.h>
#include <conio.h>
using namespace std;

int polje[100][100], p[100][100], niz[100][2];
int b, a, h, g;
  int l, m, start, end;
void print_path (int i, int j) {
  if (i!=j)
    print_path(i,p[i][j]);
  printf("(%d)", j);
}
   
/*void go() {
        min.val = 32767;
        for(int h = 0; h < a; h++) 
          if(niz[h][0] && !niz[h][1] && (niz[h][0] < min.val)) 
          min.br = h;
    }*/
int main(void) {
  struct najmanji {
    int br; int val;
  } min;     
  ifstream in("graf.txt", ios::in);
  in >> a >> b; 
  for (g = 0; g < a; g++) {
    for(h = 0; h < a; h++) {
      //if (g != h)
        polje[g][h] = 0;
    }
  }
  for(int i = 0; i < 9; i++) 
    for(int j = 0; j < 9; j++)
        p[i][j] = i;
    
  for (g = 0; g < b; g++) {
    int dist;
    in >> l >> m >> dist;
    --l;
    --m;
    polje[l][m] = dist;
  }    
  in >>start >> end;
  
  for(int i = 0; i < a; i++) niz[i][0] = polje[start][i];
  for(;;) {
      min.val = 32767; min.br = 32767;
        for(int h = 0; h < a; h++) {
          if(niz[h][0] && !niz[h][1] && (niz[h][0] < min.val)) {
            min.br = h; min.val = niz[h][0];}
        } 
      
      if(min.val == 32767) break;
      for(int i = 0; i < a; i++)
        if(polje[min.br][i])
          if(!niz[i][0] || niz[min.br][0]+polje[min.br][i]<niz[i][0])
            niz[i][0] = niz[min.br][0]+polje[min.br][i];
      niz[min.br][1] = 1;
  }    
  for(int i = 0; i < a; i++) printf("%2d", niz[i][0]);
 

  getch();
  return 0;
}
  
