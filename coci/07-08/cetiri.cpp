#include <cstdio>
#include <iostream>
using namespace std;
int a[3], sol;
int main() {
  for(int i = 0; i < 3; ++i) scanf("%d", &a[i]);
  sort(a, a+3);
  if(a[1] - a[0] == a[2]-a[1]) sol = a[2] + a[2] - a[1];
  else if(a[1] - a[0] > a[2] - a[1]) sol = a[0] + a[2] - a[1];
  else sol = a[1] + a[1] - a[0];
  printf("%d", sol);
  scanf("\n");
  return 0;
}


