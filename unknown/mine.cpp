#include <cstdio>
#include <iostream>
#define MAX 21
using namespace std;
int r, s, sol[MAX][MAX], a[MAX][MAX];
static const int dxy[10][2] = {-1,-1,-1,0,-1,1,0,-1,0,0,0,1,1,-1,1,0,1,1, 0,0};
void ispisi() {
  for(int i = 0; i < r; ++i, printf("\n"))
    for(int j = 0; j < s; ++j) {
      if(sol[i][j] == 0) printf("0");
      else if(sol[i][j] == 1) printf("1");
      else printf("?");
    }
}
int rek(int curr, int mina, int ly, int lx) {
  int &lmina = a[ly][lx];
  if(mina > lmina && lx != -1) return 0;
  if(curr == 9) {//kad posjetim sve susjede
    //ako ima dovoljno mina 
    if(mina < lmina && lx != -1) return 0;
    //slijedeci
    if(lx+1 == s) {++ly; lx = 0; }
    else ++lx;
    if(ly == r) return 1; //naso sam rjesenje
    curr = 0; mina = 0;
  }
  int ny = ly+dxy[curr][0], nx = lx+dxy[curr][1]; //curr-ti susjed od [ly][lx]
  if(ny >= r || ny < 0 || nx >= s || nx < 0) //ako sam izaso iz polja zovem dalje
    return rek(curr+1, mina, ly, lx);
  else if(sol[ny][nx] == 1) 
    return rek(curr+1, mina+1, ly, lx); //ako je tu mina onda zovem dalje
  else if(sol[ny][nx] == -1) {//ako smijem postavit cu minu
    sol[ny][nx] = 1; 
    if(rek(curr+1, mina+1, ly, lx)) return 1;
    sol[ny][nx] = 0;
    //sad probaj ne postavit minu
    if(rek(curr+1, mina, ly, lx)) return 1;
    sol[ny][nx]= -1; //kao da se nista nije dogodilo
  }
  else return rek(curr+1, mina, ly, lx); //onda ne
  return 0;
}
void solve() {
  for(int i = 0; i < r; ++i)
    for(int j = 0; j < s; ++j)
      sol[i][j] = -1;    
  rek(9, 0, 0, -1);
}
void input() {
  char str[25];
  scanf("%d %d", &r, &s);
  for(int i = 0; i < r; ++i) {
    scanf("%s", &str);
    for(int j = 0; j < s; ++j)
      a[i][j] = str[j]-'0';
  }
}
int main() {
  input(); 
  solve();
  ispisi();
  return 0;
}
