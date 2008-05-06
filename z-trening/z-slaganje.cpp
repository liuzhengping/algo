#include <cstdio>
#include <iostream>
using namespace std;

struct tree {
  int f[1 << 20], s[1 << 20];
  int from, to, offset;
  int get(int x, int lo, int hi) {
    if(lo >= to || hi <= from) return 0;
    if(lo >= from && hi <= to) return s[x];
    if(f[x]) return min(hi, to) - max(lo, from);
    return get(2*x, lo, (lo+hi)/2) + get(2*x+1, (lo+hi)/2, hi);
  }
  void add(int x, int lo, int hi, int inc) {
    if(lo >= to || hi <= from) return ;
    if(lo >= from && hi <= to) f[x] += inc;
    else {
      add(2*x, lo, (lo+hi)/2, inc);
      add(2*x+1, (lo+hi)/2, hi, inc);
    }
    if(f[x]) s[x] = hi-lo;
    else if(hi-lo > 1) s[x] = s[2*x] + s[2*x+1];
    else s[x] = 0;
  }
  tree(int N) {
    for(offset = 1; offset < N; offset *= 2) ; 
  }
} t(1 << 19);
void test() {
  for(int q, a, b; ; ) {
    scanf("%d%d%d", &q, &a, &b);
    t.from = a; t.to = b;
    if(!q) t.add(1, 0, t.offset, 1);
    else if(q < 0) t.add(1, 0, t.offset, -1);
    else {
      printf("->%d\n", t.get(1, 0, t.offset));
    }
  }
}
int main() {
  test();
  return 0;
}
