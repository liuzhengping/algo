#include <stdio.h>
#include <fstream.h>
#include <string.h>
#include <conio.h>
using namespace std;

int polje[100][100], p[100][100], con[100][100];
void print_path (int i, int j) {
  if (i!=j)
    print_path(i,p[i][j]);
  printf("(%d)", j);
}
int main(void) {
  int b, a, h, g;
  int l, m;
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
    con[l][m] = 1;
    //polje[m][l] = 0;
  }
 // printf("%d", a);
  for (int y = 0; y < a; y++)
    for(int x = 0; x < a; x++)
      if(polje[x][y])
        for (int j = 0; j < a; j++)
          if(polje[y][j] > 0)
            if (!polje[x][j] || polje[x][j] > polje[x][y] + polje[y][j]) {
              polje[x][j] = polje[x][y] + polje[y][j];
              p[x][j] = p[y][j];
 
          }    
  //scanf("%d %d", &a, &b);
  
  for(int x = 0; x < a; x++) {
    for(int y = 0; y < a; y++)
      printf("%d ", polje[x][y]);
    printf("\n");
  }
  for(int i = 0; i < a; i++)
    for(int j = 0; j < a; j++) {
        if(polje[j][i] && polje[i][j] && i != j) {
           print_path(i, j);
           printf("(%d)\n", i);
       } 
   }       
 

  getch();
  return 0;
}
  
