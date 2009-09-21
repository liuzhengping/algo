#include <cstdio>
typedef long long LL;

LL gcd(LL a, LL b) { return b ? gcd(b, a%b) : a; }

int main() {
  int a, b, c, d;
  scanf("%d/%d %d/%d", &a, &b, &c, &d);

  LL e = (LL)a*d + (LL)c*b, f = (LL)b*d;
  LL g = gcd(e, f);

  printf("%lld/%lld\n", e/g, f/g);

  return 0;
}
