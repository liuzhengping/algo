#include <cstdio>
int a[100001];
int main() {
  int n;
  scanf("%d", &n); a[n] = 0;
  for( int i = 0; i < n; ++i )
    scanf("%d", &a[i]);

  long long sol_min = 0, sol_max = 0;  
  for( int i = 0; i <= n; ++i ) {
    if( i && a[i-1] > a[i] ) sol_min += a[i-1]-a[i];
    sol_max += a[i];
  }

  printf("%lld %lld\n", sol_min, sol_max);
    
  return 0;
}
