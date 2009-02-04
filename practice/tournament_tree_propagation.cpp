#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
#define MAX (100000)
using namespace std;
const int inf = 1000000000;
struct data {
  int sum, max, min;
  int pinc, pset;
  data() { sum = 0; max = -inf; min = inf; pinc = 0; pset = inf; }
};
struct brute_force {
  int a[MAX];
  data get(int from, int to) {
    data ret;
    for( int i = from; i < to; ++i ) {
      ret.sum += a[i];
      ret.max = max(ret.max, a[i]);
      ret.min = min(ret.min, a[i]);
    }
    return ret;
  }
  void inc(int from, int to, int v) {
    for( int i = from; i < to; ++i ) {
      a[i] += v;
    }
  }
  void set(int from, int to, int v) {
    for( int i = from; i < to; ++i ) 
      a[i] = v;
  }
} bf;

struct tournament {

private:
  data a[MAX];
  int offset;
  int from, to;
  data spoji(const data& a, const data& b) {
    data ret;
    ret.sum = a.sum + b.sum;
    ret.max = max(a.max, b.max);
    ret.min = min(a.min, b.min);
    return ret;
  }
  void inc_node(int x, int lo, int hi, int v) {
    a[x].pinc += v;
    a[x].sum += v*(hi-lo);
    a[x].max += v;
    a[x].min += v;
  }
  void set_node(int x, int lo, int hi, int v) {
    a[x].pset = v;
    a[x].pinc = 0;
    a[x].sum = v*(hi-lo);
    a[x].max = v;
    a[x].min = v;
  }
  void propagiraj(int x, int lo, int hi) {
    int mid = (lo+hi)/2;
    if( a[x].pset != inf ) {
      set_node(2*x,   lo, mid, a[x].pset);
      set_node(2*x+1, mid, hi, a[x].pset);
    }
    if( a[x].pinc ) { 
      inc_node(2*x,   lo, mid, a[x].pinc);
      inc_node(2*x+1, mid, hi, a[x].pinc);
    }

    a[x].pinc = 0;
    a[x].pset = inf;
  }
  data get(int x, int lo, int hi) {
    if( lo >= to || hi <= from ) return data();
    if( lo >= from && hi <= to ) return a[x];
    
    propagiraj(x, lo, hi);
    
    return spoji( get(2*x, lo, (lo+hi)/2),
                  get(2*x+1, (lo+hi)/2, hi) );
  }
  void inc(int x, int lo, int hi, int v) {
    if( lo >= to || hi <= from ) return ;
    if( lo >= from && hi <= to ) {
      inc_node(x, lo, hi, v);
      return ; 
    }
    
    propagiraj(x, lo, hi);
    
    inc(2*x, lo, (lo+hi)/2, v);
    inc(2*x+1, (lo+hi)/2, hi, v);
    
    a[x] = spoji(a[2*x], a[2*x+1]);
  }
  void set(int x, int lo, int hi, int v) {
    if( lo >= to || hi <= from ) return ;
    if( lo >= from && hi <= to ) {
      set_node(x, lo, hi, v);
      return ;
    }
    
    propagiraj(x, lo, hi);
    
    set(2*x, lo, (lo+hi)/2, v);
    set(2*x+1, (lo+hi)/2, hi, v);

    a[x] = spoji(a[2*x], a[2*x+1]);
  }

public:
  data get(int a, int b) {
    from = a; to = b;
    return get(1, 0, offset);
  }
  void inc(int a, int b, int v) {
    from = a; to = b;
    inc(1, 0, offset, v);
  }
  void set(int a, int b, int v) {
    from = a; to = b;
    set(1, 0, offset, v);
  }
  tournament(int N) {
    for( offset = 1; offset < N; offset *= 2 ) ;
  }
} t(1);

void test() {
  int n, q;
  srand( (unsigned)time(NULL) * (int)&n );
  scanf("%d%d", &n, &q);
  
  t = tournament(n);
  t.set(0, n, 0);

  for( int i = 0; i < n; ++i ) {
    int r = rand()%2;
    //scanf("%d", &r);
    int from, to;
    from = rand()%n, to = rand()%n;
    //scanf("%d%d", &from, &to);
    if( from > to ) swap(from, to);
    if( r ) {
      int v = rand()%10;
      if( rand()%2 ) { 
        t.inc(from, to, v);
        bf.inc(from, to, v);
        printf("Inc(%3d, %3d, %3d)\n", from, to, v);
      }
      else {
        t.set(from, to, v);
        bf.set(from, to, v);
        printf("Set(%3d, %3d, %3d)\n", from, to, v);
      }
    }
    else {
      data a = t.get(from, to);
      data b = bf.get(from, to);
      printf("Get(%3d, %3d) = %d %d %d\n", from, to, a.sum, a.max, a.min);
      printf("Get(%3d, %3d) = %d %d %d\n", from, to, b.sum, b.max, b.min);
      if( a.sum != b.sum || a.max != b.max || a.min != b.min ) {
        cerr << "Error!!! Tournament ne radi dobro!!!\n";
        return ;
      }
    }
  }
  cerr << "OK, radi!\n";
}
int main() {
  test();
  return 0;
}
