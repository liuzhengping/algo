#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> dp, h;
void solve() {
   int best = 0, last = 0,lasth = h[0];
   for(int i = 1; i < n; ++i) {
     if(h[i] >= lasth) {
        best >?= (i-last-1)*lasth - (dp[i-1] - dp[last]);
        lasth = h[i];
        last = i;
     }
   }
   last = n-1; lasth = h[n-1];
   for(int i = n-2; i >= 0; --i) {
     if(h[i] >= lasth) {
        best >?= (last-i-1)*lasth - (dp[last-1] - dp[i]);
        lasth = h[i];
        last = i;
     }
   }
   printf("%d", best);
}
void input() {
  scanf("%d", &n);
  dp.resize(n); h.resize(n);
  scanf("%d", &h[0]); dp[0]= h[0];
  for(int i = 1; i < n; ++i) {
    scanf("%d", &h[i]); dp[i] = dp[i-1]+h[i];
  }
}
int main() {
  input();
  solve();
  return 0;
}
