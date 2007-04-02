#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
struct logaritamska {
  vector<int> a;
  int max;
  void insert(int x, int v) {
    for(++x;x > 0; x-=x&-x) a[x] <?= v;
  }
  int get(int x) {
    int ret = 1000000000;
    for(++x; x < max; x+=x&-x) ret <?= a[x];
    return ret;
  }
  logaritamska(int N) {
    max = N+5;
    a = vector<int>(max, N-1);
  }
};
vector<logaritamska> l;
int n, r, s;
char a[30005][31];
inline bool lijevo(int y, int x) {
  if(!x) return false;
  //printf("na pored %c, ukoso %c\n", a[y][x-1], a[y-1][x-1]);
  return a[y][x-1] == '.' && a[y+1][x-1] == '.';
}
inline bool desno(int y, int x) {
  if(x == s-1) return false;
  return a[y][x+1] == '.' && a[y+1][x+1] == '.';
}
void ispis() {
  for(int i = 0; i < r; ++i) printf("%s\n", a[i]);
}
void solve() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    int x, y; scanf("%d", &x); --x;
    y = 0;
    while(true) {
      ispis();
      y = l[x].get(y);
      
      if(y == r-1) break;
      else if(a[y+1][x] == 'X') break;
      else if(lijevo(y, x)) --x;
      else if(desno(y, x)) ++x;
      else break;  
    }
    a[y][x] = 'O';
    printf("[%d %d]", y, x);
    l[x].insert(y, y-1);
  }
}
void input() {
  scanf("%d%d", &r, &s);
  for(int i = 0; i < r; ++i) scanf("%s", a[i]);
  for(int i = 0; i < s; ++i) l.push_back(logaritamska(r));
  for(int i = 0; i < s; ++i) {
    for(int j = 0; j < r; ++j) {
      if(a[j][i] == 'X') l[i].insert(j, j-1);
    }
  }
}

int main() {
  input();
  solve();
  ispis();
  scanf("\n");
  return 0;
}
