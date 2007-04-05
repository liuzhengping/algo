#include <cstdio>
#include <iostream>
#define MAX 100050
using namespace std;
long long sum[MAX];
int n, d, to;
void solve() {
  int sol = 0;
  for(int i = 1; i <= to; ++i)
    sum[i] += sum[i-1];
  for(int x = 0; x <= to; ++x) {
    int desno = min(x+d, to);
    int lijevo = max(x-d-1, -1);
    sol >?= int(sum[desno]-sum[lijevo]);
  }
  printf("%d", sol);     
}  
void input() {
  scanf("%d%d", &n,&d);
  for(int i = 0; i < n; ++i) {
    int x, y, kol; scanf("%d%d%d", &x, &y, &kol);
    sum[x] += kol;
    to >?= x;
  }  
}  
int main() {
  input();
  solve();
  //scanf("\n");
  return 0;
}  
