#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 301

using namespace std;

int dp[MAX][MAX], max_sw, mono[MAX];

void print_arr(int *a, int n) {
  for( int i = 0; i < n; ++i ) 
    printf("%d ", a[i]);
  printf("\n");
}

int rec(int a, int b) {
  if( a == b ) return 1;
  
  int& ret = dp[a][b];

  if( ret != -1 ) return ret;

  ret = 0x3f3f3f3f;

  int last_r = 0, sw = 0, last_sgn = 0;
  for( int i = 1; i < a; ++i ) {
    int r = rec(i, b) + rec(a-i, b);
    ret = min(ret, r);
    int sgn = r-last_r;
    if( i > 1 && sgn*last_sgn < 0 ) ++sw;
    last_r = r;
    last_sgn = sgn;
  }
  max_sw = max(max_sw, sw);
  sw = 0;
  for( int i = 1; i < b; ++i ) {
    int r = rec(a, i) + rec(a, b-i);
    ret = min(ret, r);
    int sgn = r-last_r;
    if( i > 1 && sgn*last_sgn < 0 ) ++sw;
    last_r = r;
    last_sgn = sgn;
    mono[i] = r;
  }
  max_sw = max(max_sw, sw);

  print_arr(mono, b);

  return ret;
}

int greedy(int a, int b) {
  if( a == b ) return 1;

  if( a > b ) {
    return greedy(b, b) + greedy(a-b, b);
  }
  return greedy(a, a) + greedy(a, b-a); 
}

int main() {
  memset(dp, -1, sizeof(dp));
  int a, b;
  scanf("%d%d", &a, &b);
  
  printf("%d\n", rec(a, b));
  printf("%d\n", greedy(a, b));
  printf("Sw: %d\n", max_sw);

  return 0;
}
