#include <cstdio>

#define MAX 5

int n, M, a[MAX][MAX], empty[MAX][MAX], start_mask, square_of_n;
int rowsum[MAX], colsum[MAX], diagsum[2];

int ok(int r, int c, int x) {
  if( c == n-1 ) {
    if( rowsum[r]+x != M ) return 0;
  }
  else if( c && rowsum[r]+x > M ) return 0;

  if( r == n-1 ) {
    if( colsum[c]+x != M ) return 0;
  }
  else if( r && colsum[c]+x > M ) return 0;

  if( c == n-1 && r == n-1 ) {
    if( diagsum[0]+x != M ) return 0;
  }
  else if( r && r == c && diagsum[0]+x > M ) return 0;

  if( c == 0 && r == n-1 ) {
    if( diagsum[1]+x != M ) return 0;
  } else if( r && r+c == n-1 && diagsum[1]+x > M  ) return 0;
  
  return 1;
}

void place(int r, int c, int x) {
  a[r][c] = x;
  rowsum[r] += x;
  colsum[c] += x;
  if( r == c ) diagsum[0] += x;
  if( r+c == n-1 ) diagsum[1] += x;
}

void remove(int r, int c, int x) {
  a[r][c] = 0;
  rowsum[r] -= x;
  colsum[c] -= x;
  if( r == c ) diagsum[0] -= x;
  if( r+c == n-1 ) diagsum[1] -= x;
}

void print() {
  for( int i = 0; i < n; ++i, printf("\n") )
    for( int j = 0; j < n; ++j ) 
      printf("%d ", a[i][j]);
  printf("\n");
}

void printmask(int mask) {
  for( int i = 1; i <= square_of_n; ++i ) 
    printf("%d", !!((1<<i)&mask));
  printf("\n");
}

int solve(int mask, int r, int c) {
  if( r == n ) return 1;

  int nr = (c == n-1 ? r+1 : r), nc = (c == n-1 ? 0 : c+1);

  if( !empty[r][c] ) {
    if( ok(r, c, a[r][c]) ) {
      place(r, c, a[r][c]);
      return solve(mask | (1<<a[r][c]), nr, nc);
    }
    return 0;
  }

  for( int i = square_of_n; i > 0; --i )
    if( !((1<<i) & mask) && ok(r, c, i) ) {
      place(r, c, i);
      int found = solve(mask | (1<<i), nr, nc);
      if( found ) return 1;
      else remove(r, c, i);
    }

  return 0;
}

void input() {
  scanf("%d", &n);
  for( int i = 0; i < n; ++i ) 
    for( int j = 0; j < n; ++j ) {
      scanf("%d", &a[i][j]);
      if( a[i][j] == 0 )
        empty[i][j] = 1;
      else
        start_mask |= 1 << a[i][j];
    }
  M = n*(n*n+1)/2;
  square_of_n = n*n;
}

void output(int found) {
  if( !found ) {
    printf("-1\n");
    return ;
  }

  for( int i = 0; i < n; ++i, printf("\n") )
    for( int j = 0; j < n; ++j ) 
      printf("%d ", a[i][j]);
}


int main() {
  input();
  output(solve(start_mask, 0, 0));

  return 0;
}
