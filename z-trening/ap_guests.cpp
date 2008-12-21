#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAX 400005
using namespace std;
int a[MAX], n;
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  sort(a, a+n);
  int k = 2, sol = 0;
  for(int i = 0; i < n-2; ++i) {
    for(; k < n && a[i] + a[i+1] > a[k]; ++k) ;
    sol = max(sol, k-i);
  }
  printf("%d\n", sol);
  return 0;
}
