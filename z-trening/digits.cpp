#include <cstdio>
int main() {
  int n, k, sol = 0;
  scanf("%d%d", &n, &k);

  for( int i = 0; i <= n; ++i ) {
    int sum = 0;
    for( int r = i; r; r /= 10 ) 
      sum += r%10;
    if( sum == k )
      ++sol;
  }

  printf("%d\n", sol);

  return 0;
}
