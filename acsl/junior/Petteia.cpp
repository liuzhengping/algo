#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
int grid[10][10], lol; //mora bit min grid[9][9] jer popunjavamo od 1 do 8
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1}; 
void provjera(int y, int x) {
  int p = false;
  printf("Output #%d: ", ++lol);
  for(int sm = 0; sm < 4; sm++){
    if(grid[y+dy[sm]][x+dx[sm]]==1 && grid[y+2*dy[sm]][x+2*dx[sm]] == 2){
        printf("%d,%d\t", y + dy[sm], x + dx[sm]);  
        p=true;
      }  
    }  
  if(!p) printf("NONE\n");
  else printf("\n");
}  
int main() {
  int a, b, n;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d%d", &a, &b);
    grid[a][b] = 1; //1 je O
  }
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d%d", &a, &b);
    grid[a][b] = 2; //2 je X
  }    
  for(int i = 0; i < 5; ++i) {
    scanf("%d%d", &a, &b);
    grid[a][b] = 2; //2 je X
    provjera(a, b);
  }  
  scanf("\n");
  return 0;
}
/*
4 1 8 2 8 6 3 6 6
7 1 7 2 7 3 8 5 3 7 3 6 5 6 7
7 3
5 6
5 3
3 8
1 7
*/


