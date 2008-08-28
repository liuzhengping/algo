#include <cstdio>
#include <iostream>
int cost[4], a[105];
int main() {
  for(int i = 1; i <= 3; ++i) scanf("%d", &cost[i]);
  for(int i = 0; i < 3; ++i) {
    int from, to;
    scanf("%d%d", &from, &to);
    for(int i = from; i < to; ++i)
      ++a[i];
  }
  int sol = 0;
  for(int i = 0; i < 105; ++i)
    sol += a[i] * cost[ a[i] ];
  printf("%d\n", sol);
  return 0;
}
