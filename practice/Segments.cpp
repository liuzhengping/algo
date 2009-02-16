#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1005
using namespace std;
#define x first
#define y second
typedef long long LL;
typedef pair<int, int> point;
typedef pair<LL, LL> frac;
const int inf = 1000000000;
int n, nn;

LL gcd(LL a, LL b) { return (!b ? a : gcd(b, a%b)); }
void fix(frac& f) {
  if( f.second < 0 ) {
    f.second = -f.second;
    f.first = -f.first;
  }
  if( f.second == 0 ) { f.first = 1; return ; }
  else if( f.first == 0 ) { f.second = 1; return ; }
  LL g = gcd(abs(f.first), abs(f.second));
  f.first /= g;
  f.second /= g;
}
void recip(frac &f) {
  swap(f.first, f.second);
  fix(f);
}
frac operator+(const frac& a, const frac& b) {
  frac ret(a.first*b.second+a.second*b.first, a.second*b.second);
  fix(ret);
  return ret;
}
frac operator-(const frac& a, const frac& b) {
  frac t = b;
  t.first = -t.first;
  fix(t);
  return t+a;
}
frac operator*(const frac& a, const frac& b) {
  frac ret(a.first*b.first, a.second*b.second);
  fix(ret);
  return ret;
}
frac operator/(const frac& a, const frac& b) {
  frac t = b;
  recip(t);
  return a*t;
}
struct segment;
struct equation {
  frac a, b;
  void print() {
    printf("y= (%lld/%lld)*x + %lld/%lld\n", a.first, a.second, b.first, b.second);
  }
  equation() { }
  equation(const point& A, const point& B) {
    a = frac(B.y-A.y, B.x-A.x);
    fix(a);
    b = a*frac(-A.x, 1) + frac(A.y, 1);
    if( a.second == 0 ) b = frac(A.x, 1);
  }
  friend bool operator<(const equation& A, const equation& B) {
    if( A.a < B.a ) return true;
    if( A.a > B.a ) return false;
    return A.b < B.b;
  }
  friend bool operator==(const equation& A, const equation& B) {
    return A.a==B.a && A.b==B.b;
  }
  friend pair<frac, frac> find_ip(equation A, equation B) {
    if( A.a.second == 0 ) swap(A, B);
    if( B.a.second == 0 ) 
      return make_pair(B.b, A.a*B.b+A.b);
    frac f = (A.b-B.b)/(B.a-A.a);
    return make_pair(f, A.a*f+A.b);
  }
};
LL ccw(const point& A, const point& B, const point& C) {
  return (LL)A.x*(B.y-C.y)+(LL)B.x*(C.y-A.y)+(LL)C.x*(A.y-B.y);
}
bool same_sgn(LL a, LL b) { return a>=0 && b>=0 || a<=0 && b<=0; } 
struct segment {
  point a, b;
  equation eq;
  void print() { printf("(%d %d %d %d)", a.x, a.y, b.x, b.y); }
  segment() { }
  segment(const point& a, const point& b) : a(a), b(b), eq(a, b) { 
    if( b < a ) swap(this->a, this->b); 
  }
  friend bool operator<(const segment& A, const segment& B) {
    if( A.a < B.a ) return true;
    if( A.a > B.a ) return false;
    return A.b < B.b;
  }
  friend bool intersects(const segment& A, const segment& B) {
    if( A.eq == B.eq ) {
      if( A < B ) return A.b >= B.a;
      return B.b >= A.a;
    }
    LL d1 = ccw(A.a, A.b, B.a);
    LL d2 = ccw(B.b, B.a, A.a);
    LL d3 = ccw(A.b, A.a, B.b);
    LL d4 = ccw(B.a, B.b, A.b);
    return same_sgn(d1, d3) && same_sgn(d2, d4);
  }
} seg[MAX], nseg[MAX];
struct cmp_by_eq {
  bool operator()(const segment& A, const segment& B) {
    if( A.eq < B.eq ) return true;
    if( B.eq < A.eq ) return false;
    return A < B;
  }
};

bool check() {
  for( int i = 0; i < n; ++i ) 
    for( int j = i+1; j < n; ++j ) 
      if( seg[i].eq == seg[j].eq && intersects(seg[i], seg[j]) ) {
        printf("(Error %d %d\n)", i, j);
        return false;
      }
  return true;
}

void sweep(int from, int to) {
  printf("Sweep(%d, %d)\n", from, to);
  point lo = seg[from].a, hi = seg[from].b;
  for( int i = from; i < to; ++i ) {
    if( i > from && seg[i].a > hi ) {
      nseg[nn++] = segment(lo, hi);
      lo = seg[i].a;
      hi = seg[i].b;
    }
    else if( seg[i].b > hi ) 
      hi = seg[i].b;
  }
  nseg[nn++] = segment(lo, hi);
}
void print_segs() {
  printf("printing..\n");
  for( int i = 0; i < n; ++i ) 
    printf("(%d %d %d %d)\n", seg[i].a.x, seg[i].a.y, seg[i].b.x, seg[i].b.y);
  printf("Done\n");
}
void solve() {
  sort(seg, seg+n, cmp_by_eq());
  print_segs();
  int k;
  for( int i = 0; i < n; i = k ) {
    for( k = i+1; k < n && seg[k].eq == seg[k-1].eq; ++k ) ;
    sweep(i, k);
  }
  
  memcpy(seg, nseg, sizeof(nseg));
  n = nn;
  print_segs();

  if( !check() ) printf("ERRORS\n");
  else printf("Everything OK\n");
}
void input() {
  scanf("%d", &n);
  for( int i = 0; i < n; ++i ) {
    point a, b;
    scanf("%d%d%d%d", &a.x, &a.y, &b.x, &b.y);
    seg[i] = segment(a, b);
  }
  
}
void test() {
  for( segment s1, s2;; ) {
    point a, b;
    scanf("%d%d%d%d", &a.x, &a.y, &b.x, &b.y);
    s1 = segment(a, b);
    s1.print();
    s1.eq.print();
    scanf("%d%d%d%d", &a.x, &a.y, &b.x, &b.y);
    s2 = segment(a, b);
    s2.print();
    s2.eq.print();
    if( !intersects(s1, s2) ) printf("No intersection\n");
    else {
      pair<frac, frac> ff = find_ip(s1.eq, s2.eq);
      printf("Point: %lld/%lld, %lld/%lld\n", ff.first.first, ff.first.second, ff.second.first, ff.second.second);
    }
  }
}
int main() {
  //test();
  input();
  solve();
  return 0;
}
/*
10
2 2 7 7
5 5 10 10
1 0 3 0
11 11 15 15
5 6 10 12
10 12 40 48
-1 -1 1 1
0 0 -3 -3
0 1 1 0
0 5 5 0

 */
