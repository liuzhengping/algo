#include <cstdio>
#include <iostream>
using namespace std;
int n, sol, freq[7];
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    ++freq[x];
    sol = max(sol, freq[x]);
  }
  printf("%d\n", 10*sol);

  return 0;
}



