#include <stdio.h>
#include <fstream.h>
#include <string.h>
#include <conio.h>
using namespace std;

int polje[100][100];

int main(void) {
  int b, a, h, g;
  int l, m;
  ifstream in("graf.txt", ios::in);
  in >> a >> b;
  for (g = 0; g < a; g++) {
    for(h = 0; h < a; h++) {
      //if (g != h)
        polje[g][h] = 0x1001;
    }
  }
  for (g = 0; g < b; g++) {
    int dist;
    in >> l >> m >> dist;
    --l;
    --m;
    polje[l][m] = dist;
    polje[m][l] = 0x1001;
  }
 // printf("%d", a);
  for (g = 0; g < a; g++)
    for(l = 0; l < a; l++)
      for (m = 0; m < a; m++)
        if (polje[l][m] > polje[l][g] + polje[g][m])
           polje[l][m] = polje[l][g] + polje[g][m];
  //scanf("%d %d", &a, &b);
  for(int x = 0; x < a; x++) {
    for(int y = 0; y < a; y++)
      printf("%d ", polje[x][y]);
    printf("\n");
  }    

  getch();
  return 0;
}
  
