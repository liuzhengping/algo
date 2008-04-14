#include <cstdio>
#include <vector>
#include <iostream>
#define MAX 578
using namespace std;
struct ttree {
  struct data {
    int sum;
    int prop;
    data() { sum = 0; prop = 0; }
  };
  int offset, from, to;  
  vector<data> a;
  vector<int> bf;
  void print() {
    for(int i = 0; i < 16; ++i) printf("%d", a[i].sum);
    printf("\n");
    for(int i = 0; i < 16; ++i) printf("%d", a[i].prop);
    printf("\n\n");
  }  
  void insert(int pos, int v) {
    pos += offset;
    a[pos].sum = v;
    for(pos /= 2; pos > 0; pos /= 2) {
      a[pos].sum = a[2*pos].sum + a[2*pos+1].sum;
    }  
  }  
  void propagiraj(int x) {
    a[2*x].prop += a[x].prop;
    a[2*x+1].prop += a[x].prop;
  }  
  int sum(int x, int lo, int hi) {
    if(lo >= to || hi <= from) return 0;
    a[x].sum += a[x].prop * (hi - lo);
    if(hi-lo > 1) propagiraj(x);
    a[x].prop = 0;
    if(lo >= from && hi <= to)
      return a[x].sum;
    return sum(2*x, lo, (lo+hi)/2) + sum(2*x+1, (lo+hi)/2, hi);
  }  
  void brute_ins(int a, int b, int v) {
    for(int i = a; i < b; ++i) bf[i] += v;
  }  
  int brute_get(int a, int b) {
    int ret = 0;
    for(int i = a; i < b; ++i)
      ret += bf[i];
    return ret;
  }  
  int get_sum(int a, int b) {
    from = a;
    to = b;
    return sum(1, 0, offset);
  }      
  void range(int x, int lo, int hi, int d) {
    if(lo >= to || hi <= from) return ;
    if(lo >= from && hi <= to) {
      a[x].prop += d;
      a[x].sum += a[x].prop * (hi - lo);
      if(hi-lo > 1) propagiraj(x);
      a[x].prop = 0;
      return ;
    }  
    a[x].sum += d * ( min(hi, to) - max(lo, from) );
    a[x].sum += a[x].prop * (hi - lo);
    if(hi-lo > 1) propagiraj(x);
    a[x].prop = 0;
    range(2*x, lo, (lo+hi)/2, d);
    range(2*x+1, (lo+hi)/2, hi, d);
  }  
  void insert_range(int a, int b, int v) {
    from = a;
    to = b;
    brute_ins(a, b, v);
    //for(int i = a; i < b; ++i) insert(i, v);
    range(1, 0, offset, v);
  }  
  ttree(int N) {
    for(offset = 1; offset < N; offset *= 2) ;
    a = vector<data>(2*offset);
    bf = vector<int>(offset);
  }  
} t(MAX);  
void gen() {
  srand( time(0) );
  for(int i = 0; i < 100000; ++i) {
    int a = rand()%MAX;
    int b = a + rand()%(MAX-a);
    int c = rand()%2;
    if(c) t.insert_range(a, b, 1);
    else {
      if(t.get_sum(a, b) != t.brute_get(a, b)) printf("Error!");
      //printf("->%d (%d)\n", t.get_sum(a, b), t.brute_get(a, b));
    }  
  }  
  printf("Gotov gen\n");
}
void probaj() {
  for(int a, b, c, q; ; ) {
    scanf("%d", &q);
    if(!q) {
      scanf("%d%d", &a, &b);
      t.insert_range(a, b, 1);
    }
    else {
      scanf("%d%d", &a, &b);
      printf("->%d (%d)\n", t.get_sum(a, b), t.brute_get(a, b));
    }   
    t.print();   
  } 
}    
int main() {
  //probaj();
  gen();
  scanf("\n");
  return 0;
}


