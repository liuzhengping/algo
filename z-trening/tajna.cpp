#include <cstdio>
#include <cstring>
int main() {
  char s[105], sol[105];
  int n, r, c, len = 0;
  scanf("%s", s);
  n = strlen(s);

  for( int i = 1; i*i <= n; ++i ) 
    if( n % i == 0 )
      r = i;
  c = n/r;
  
  for( int i = 0; i < r; ++i ) {
    for( int j = i; j < n; j += r )
      sol[len++] = s[j];
  }

  sol[len] = 0;
  printf("%s\n", sol);

  return 0;
}
