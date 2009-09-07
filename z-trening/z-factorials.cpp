#include <cstdio>
#include <cstring>

int main() {
  int n = 0, k = 0;
  char s[32];
  scanf("%s", &s);
  int len = strlen(s);
  for( int i = 0; i < len; ++i ) 
    if( s[i] == '!' ) {
      k = len-i;
      break;
    }
    else n = 10*n + s[i]-'0';


  int sol = 1;
  for( int i = n; i > 1; i -= k ) 
    sol *= i;

  printf("%d\n", sol);

  return 0;
}
