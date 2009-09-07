#include <cstdio>
#include <ctime>
#include <cstdlib>

#define MAX 1000

int sum[MAX];
int n = 20;

int brute(int k) {
  int i, curr = 0;
  for( i = 0; i < n && curr+sum[i] < k; ++i ) ;
  return i;
}

int ok(int mid, int k) {
  return sum[mid] >= k; 
}

int bs2(int k) {
  int lo = 0, hi = n, mid, ret = hi;
  for( ; lo < hi;  ) {
    mid = (lo+hi)/2;
    if( ok(mid, k) ) {
      hi = mid;
      ret = mid;
    }
    else lo = mid+1;
  }
  return ret;
}

int bs(int k) {
  int lo = 0, hi = n, mid;
  while( lo <= hi ) {
    mid = (lo+hi)/2;
    if( ok(mid, k) ) {
      hi = mid-1;
    }
    else {
      lo = mid+1;
    }
  }
  return (lo > n ? n : lo);
}

void test() {
  for( int k = -1; k < 500; ++k ) {
    //scanf("%d", &k);
    int real = bs2(k);
    int bf = brute(k);
    if( real != bf ) {
      fprintf(stderr, "ERROR: %d %d\n", real, bf);
      return ;
    }
    printf("%d > %d\n", k, real);
  }
}

void print() {
  for( int i = 0; i < n; ++i ) 
    printf("%d ", sum[i]);
  printf("\n");
}

void generate() {
  int seed;
  srand(time(NULL)+(int)&seed);
  sum[0] = rand()%10;
  for( int i = 1; i < n; ++i ) {
    sum[i] = sum[i-1] + rand()%2 * (rand()%3);
  }
}

int main() {
  generate();
  print();
  test();
  
  return 0;
}
