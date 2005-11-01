#include <stdio.h>
#include <fstream.h>
#include <string.h>
#include <conio.h>
#include <queue>
using namespace std;
int polje[100][100]; int val[100]; int krug;
int id = -1;
int a;
void visit(int k) {
    val[k] = ++id;
    for(int t = 0; t < a; t++) {
      
      if(polje[k][t] != 0) {
        if(polje[t][krug]) printf("\nkrug pronadjen, (%d)!", t);
        if(val[t] == 0) visit(t);
    }    
    }
    //val[k] = 0;   
    
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
    polje[l][m] = dist; //polje[m][l] = dist;
    //polje[m][l] = 0;
  }
 // printf("%d", a);
 for(krug = 0; krug < a; krug++) {
     for(int i = 0; i < a; i++) val[i] = 0;
     id = -1;
     visit(krug);
 }    
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
