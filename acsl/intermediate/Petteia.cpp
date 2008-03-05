#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
int grid[9][9], lol; //mora bit min grid[9][9] jer popunjavamo od 1 do 8
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1}; 
bool ok(int y, int x) { return x > 0 && x <= 8 && y > 0 && y <= 8; } //dal su dobre koordinate
void provjera(int y, int x, int igrac) { //provjera dal je IGRAC capturao protivnika
  queue< pair<int, int> > curr, sol;
  for(int dir = 0; dir < 4; ++dir) {//prosiri se u svim smjerovima pravocrtno
    curr = queue< pair<int, int> >(); //brise curr (posto nema .clear()
    int cx = x, cy = y, bio = 0; //dal je bilo capturea
    for( cx += dx[dir], cy += dy[dir]; ok(cx, cy); cx += dx[dir], cy += dy[dir] ) {
      if(grid[cy][cx] == igrac) { //ako je nadjen drugi marker od IGRACA
        bio = 1; //onda je mozda bilo capturea
        break; //moras izac ovdje jer se dalje onda nemoze capturat
      }  
      if(grid[cy][cx]) //ako je nadjen protivnicki marker stavi ga na popis mogucih capturea
        curr.push( make_pair(cy, cx) ); 
      else {//ako je nadjeno prazno polje onda izbrisi popis capturea jer ih nema onda
        curr = queue< pair<int, int> >(); //brise curr (posto nema .clear()
        break; // moras isto izadj iz petlje
      }  
    }
    if(bio)
      for( ; !curr.empty(); curr.pop() )  //prodji kroz popis sigurnih capturea i spremi ga u sol
        sol.push( curr.front() );  
  } 
  printf("Output #%d: ", ++lol); 
  if(sol.empty()) printf("NONE\n"); //ako je prazan sol onda nema captura
  else {
    for(int prvi_put = 1; !sol.empty(); sol.pop(), prvi_put = 0 ) {//ispis popisa capturea
      if(!prvi_put) printf(" and ");
      printf("%d, %d", sol.front().first, sol.front().second);
    }
    printf("\n");
  }    
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
    provjera(a, b, 2); //provjeri za capture; 2 je zato sto gledam sta je X capturao
  }  
  scanf("\n");
  return 0;
}
/*
5 1 8 2 8 5 4 5 5 6 3
6 1 7 2 7 3 8 5 3 5 6 7 3
7 3
5 6
5 3
3 8
1 7
*/


