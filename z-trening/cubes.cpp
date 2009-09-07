#include <cstdio>

typedef long long LL;


int ok(LL k) {
  for( LL a = 2; a*a <= k; ++a )
    if( k % a == 0 ) 
      return 1;
  return 0;
}

int main() {
  int n;
  scanf("%d", &n);
  while( n-- ) {
    LL k;
    scanf("%lld", &k);
    printf("%s\n", ok(k) ? "DA" : "NE");
  }

  return 0;
}
