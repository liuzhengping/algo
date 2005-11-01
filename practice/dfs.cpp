#include <stdio.h>
#include <fstream.h>
#include <string.h>
#include <conio.h>
using namespace std;
int id = -1;
int a;
int polje[100][100]; int val[100];
void visit(int k) {
    val[k] = ++id;
    if(id == a) { 
      for(int i = 0; i < a; i++) printf("%d ", val[i+1]);
      printf("\n");
  }    
    
    for(int t = 0; t < a; t++)
      if(polje[k][t] != 0)
        if(val[t] == 0) visit(t);
    id--; val[k] = 0;
    
}    
int main(void) {
  int b, h, g;
  int l, m;
  ifstream in("graf.txt", ios::in);
  in >> a >> b;
  for (g = 0; g < a; g++) {
    for(h = 0; h < a; h++) {
      //if (g != h)
        polje[g][h] = 0;
    }
  }
  for (g = 0; g < b; g++) {
    int dist;
    in >> l >> m >> dist;
    --l;
    --m;
    polje[l][m] = dist; polje[m][l] = dist;
    //polje[m][l] = 0;
  }
 // printf("%d", a);
  visit(0);
  //scanf("%d %d", &a, &b);
  printf("\n");
  for(int x = 0; x < a; x++) {
    for(int y = 0; y < a; y++)
      printf("%d ", polje[x][y]);
    printf("\n");
  }    

  getch();
  return 0;
}
/*
6 9
1 2 3
1 5 2
2 3 1
3 4 4
4 2 2
4 1 4
4 6 5
5 3 2
6 5 1
 */ 
