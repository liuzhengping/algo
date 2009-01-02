#include <cstdio>
#include <iostream>
#include <queue>
#include <assert.h>
#define MAX 102
using namespace std;
int n, sx, sy, ex, ey, a[MAX];
int dist[MAX][MAX][MAX];
struct stanje {
  int x, y, p;
  void up() {
    if ( --y < 0 )
      y = n - 1;
    if ( p <= a[y] )
      x = p;
    else
      x = a[y];
  }
  void down() {
    if ( ++y == n )
      y = 0;
    if ( p <= a[y] )
      x = p;
    else
      x = a[y];
  }
  void left() {
    if ( --x < 0 )
      { if ( --y < 0 )
        y = n - 1; x = a[y]; }
    p = min( x, a[y] );
  }
  void right() {
    if ( ++x > a[y] )
      { if ( ++y == n )
        y = 0; x = 0; }
    p = x;
  }
  stanje( int x, int y, int p ) : x( x ), y( y ), p( p ) { }
};
int solve() {
  memset( dist, -1, sizeof( dist ) );
  queue<stanje> q;
  dist[sx][sy][sx] = 0;
  for ( q.push( stanje( sx, sy, sx ) ); !q.empty(); q.pop() ) {
    stanje u = q.front();
    if ( u.x == ex && u.y == ey )
      return dist[u.x][u.y][u.p];
    for ( int i = 0; i < 4; ++i ) {
      stanje ns = u;
      if ( i == 0 )
        ns.up();
      else
        if ( i == 1 )
          ns.down();
        else
          if ( i == 2 )
            ns.left();
          else
            if ( i == 3 )
              ns.right();
      if ( dist[ns.x][ns.y][ns.p] == -1 ) {
        dist[ns.x][ns.y][ns.p] = dist[u.x][u.y][u.p] + 1;
        q.push( ns );
      }
    }
  }
  return 0;
}
void input() {
  scanf( "%d", &n );
  for ( int i = 0; i < n; ++i )
    scanf( "%d", &a[i] );
  scanf( "%d%d%d%d", &sy, &sx, &ey, &ex );
  --sy;
  --ey;
}
int main() {
  input();
  printf( "%d\n", solve() );
  return 0;
}
