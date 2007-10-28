#include <cstdio>
#include <iostream>
#define MAX 8
using namespace std;
typedef long long LL;
LL povrh(int n, int k) {
  LL ret = 1;
  for(int x = n; x > k; --x)
    ret = (ret*x)/(n-x+1);
  return ret;
}  
LL dp[MAX+1][MAX*MAX/2], b[MAX+1];
int main() {
  for(int i = 0; i <= MAX; ++i) b[i] = povrh(MAX, i);
  dp[0][0] = 1;
  for(int curr = 1; curr <= MAX; ++curr)
    for(int i = 0; i <= MAX*MAX/2; ++i)
      for(int j = 0; j <= MAX; ++j)
        if(i >= j)
          dp[curr][i] += dp[curr-1][i-j] * b[j];      
  cout << "Rj: " << dp[MAX][MAX*MAX/2];
  scanf("\n");
  return 0;
}


