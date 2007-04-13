#include <cstdio>
#include <iostream>
#define MAX 130
using namespace std;
const int inf = 1000000000;
int n, a[MAX], memo[MAX][MAX], sum;
int rek(int from, int to) {
  if(from > to) return 0;
  if(memo[from][to] != inf) return memo[from][to];
  return memo[from][to] = max(a[from] - rek(from+1, to), a[to] - rek(from, to-1));
}  
void solve() {
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j) memo[i][j] = inf;
  printf("%d", (sum+rek(0, n-1))/2);
  //rekurzija vraca koliko vise moze skupiti Slavko pa je potrebno rjesiti sustav jednadzbi da dobijem ukupno
}  
void input() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {scanf("%d", &a[i]); sum+=a[i];}
}  
int main() {
  input();
  solve();
  return 0;
}

