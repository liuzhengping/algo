#include <cstdio>
#include <iostream>
#include <vector>
#define MAX 8
#define MR 15
using namespace std;
struct bf {
  vector<int> a;
  void remove(int lo, int hi) {
    for(int i = lo; i < hi; ++i)
      --a[i];
  }  
  void insert(int lo, int hi) {
    for(int i = lo; i < hi; ++i)
      ++a[i];
  }
  int get(int lo, int hi) {
    int ret = 0;
    for(int i = lo; i < hi; ++i)
      ret >?= a[i];
    return ret;
  }      
  bf(int N) { a = vector<int>(N, 0); }
} bf(MAX);  
struct tournament {
  struct data {
    int sum, max, prop, mp;
  }; 
  vector<data> a; 
  int offset, from, to;
  void print() {
    int curr = 1;
    for(int i = 1; i < 2*offset; i = (1 << curr++)) {
      //for(int j = 0; j < 2*(offset-curr-1); ++j)
        //printf(" ");
      for(int j = i; j < (1 << curr); ++j)
        printf("(%d %d) ", a[j].sum, a[j].prop);
      printf("\n");
    } 
    for(int i = 0; i < offset; ++i)
      printf("( %d ) ", bf.a[i]);
    printf("\n-----------\n"); 
  }  
  void propagiraj(int x) {
    a[2*x].prop += a[x].prop;
    a[2*x].mp += a[x].mp;
    a[2*x+1].prop += a[x].prop;
    a[2*x+1].mp += a[x].mp;
  }
  int get(int x, int lo, int hi) {
    if(lo >= to || hi <= from) return 0;
    a[x].sum += a[x].prop*(hi-lo);
    a[x].max += a[x].mp;
    if(hi-lo > 1) propagiraj(x);
    a[x].prop = a[x].mp = 0;
    if(lo >= from && hi <= to) return a[x].max;
    return max( get(2*x, lo, (lo+hi)/2), get(2*x+1, (lo+hi)/2, hi) );
  }
  void insert(int x, int lo, int hi, int inc) {
    if(lo >= to || hi <= from) return ;
    a[x].sum += a[x].prop*(hi-lo);
    a[x].max += a[x].mp;
    if(hi-lo > 1) propagiraj(x);
    a[x].prop = a[x].mp = 0;
    if(lo >= from && hi <= to) {
      a[x].prop += inc;
      a[x].sum += a[x].prop*(hi-lo);
      a[x].max += inc;
      a[x].mp += inc;
      if(hi-lo > 1) propagiraj(x);
      a[x].prop = a[x].mp = 0;
      return ;
    }
    a[x].sum += inc*(min(hi, to) - max(lo, from));
    insert(2*x, lo, (lo+hi)/2, inc);
    insert(2*x+1, (lo+hi)/2, hi, inc);
    a[x].max = max( a[2*x].max, a[2*x+1].max );
  }
  tournament(int N) {
    for(offset = 1; offset < N; offset *= 2) ;
    a = vector<data>(2*offset);
  }  
} t(MAX);  
int gen() {
  srand(time(0));
  for(int i = 0; i < 1000; ++i) {
    int a = rand()%(MAX-MR);
    int b = a + rand()%MR+1;
    printf("(%d %d)", a, b);
    if(a >= t.offset || a < 0 || b >= t.offset || b < 0) {
      printf("ERORROROEOORR\n");
      return 0;
    }
    if(rand()%2) {
      printf("> GET -> \n");
      t.from = a;
      t.to = b;
      int B = bf.get(a, b);
      int A = t.get(1, 0, t.offset);
      if(A != B) { printf("(%d != %d)", A, B); 
        return 0;}
    } 
    else {
      printf("> INSERT \n");
      bf.insert(a, b);
      t.from = a;
      t.to = b;
      t.insert(1, 0, t.offset, 1);
    }   
  } 
  return 1; 
}  
void test() {
  for(int q, a, b; ; ) {
    scanf("%d%d%d", &q, &a, &b);
    if(q < 0) {
      bf.remove(a, b);
      t.from = a;
      t.to = b;
      t.insert(1, 0, t.offset, -1);
    } 
    else if(q > 0) {
      t.from = a;
      t.to = b;
      printf("->%d == %d\n", bf.get(a, b), t.get(1, 0, t.offset) );
    }
    else {
      bf.insert(a, b);
      t.from = a;
      t.to = b;
      t.insert(1, 0, t.offset, 1);
    }  
    t.print();   
  }  
}   
int main() {
  //if( gen() )
    //printf("ALL TESTS PASSED!\n");
  //else printf("ERRORS!");
  test();
  return 0;
}  
