#include <cstdio>

#define MAX_A 65536
#define MAX_N 100000

int hash[MAX_A], dehash[MAX_A], numbers[MAX_A], sum[MAX_A];
int input[MAX_N][2];
int max_a, distinct;

int min(int k) {
  int lo = 0, hi = distinct, mid;
  for( int itr = 0; itr < 9; ++itr ) {
    mid = (lo+hi)/2;
    if( sum[mid] >= k ) hi = mid-1;
    else lo = mid+1;
  }
  return lo > distinct ? distinct : lo;
}

void solve() {
  
}

void preprocess() {
  for( int i = 0; i <= max_a; ++i ) {
    if( numbers[i] ) {
      hash[i] = distinct;
      dehash[distinct] = i;
      sum[distinct] = (distinct ? sum[distinct-1] : 0) + numbers[i];
      ++distinct;
    }
  }
}

void input() {
  scanf("%d", &n);
  for( int i = 0; i < n; ++i ) {
    scanf("%d%d", &input[i][0], &input[i][1]);
    numbers[input[i][1]]++;
    if( input[i][1] > max_a ) max_a = input[i][1];
  }
}

int main() {
  input();
  solve();
  return 0;
}
