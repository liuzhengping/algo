#include <cstdio>
#include <cmath>

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  printf("%lld\n", (long long) ceil(k*log(n)/log(10)+1e-4));

  return 0;
}
