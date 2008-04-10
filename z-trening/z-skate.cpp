#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#define MAX 100005
#define MOD 10000
using namespace std;
vector< pair<int, int> > gal;
vector<int> v;
map<int, int> hash;
int n;
int dp[MAX];
void sazmi() {
  sort(v.begin(), v.end());
  v.erase( unique(v.begin(), v.end()), v.end() );
  for(int i = 0; i < v.size(); ++i)
    hash[ v[i] ] = i+1;
  for(int i = 0; i < n; ++i) {
    gal[i].first = hash[ gal[i].first ];
    gal[i].second = hash[ gal[i].second ];
    printf("(%d %d)\n", gal[i].second, gal[i].first);
  }
}
void solve() {
  gal.push_back( make_pair(0, 0) );
  ++n;
  sort(gal.begin(), gal.end());
  int last = 0;
  dp[0] = 1;
  for(int i = 1; i < n; ++i) {
    vector< pair<int, int> >::iterator it = lower_bound(gal.begin(), gal.end(), make_pair(gal[i].second, 0));
    --it;
    dp[i] = (dp[i] + dp[ it-gal.begin() ])%MOD;
    if( gal[last].first  >= gal[i].second) {printf("(last = %d (%d)\t", last, dp[last]);
      dp[i] = (dp[i] + dp[last])%MOD; }
    last = i;
      printf("%d: %d -> %d\n", gal[i].first, it->first, dp[ it-gal.begin() ]);
    printf("[%d]\n", dp[i]);
  }
  printf("%d\n", dp[n-1]);
}
void input() {
  scanf("%d", &n);
  gal.resize(n);
  for(int i = 0; i < n; ++i) {
    scanf("%d%d", &gal[i].second, &gal[i].first);
    v.push_back(gal[i].first);
    v.push_back(gal[i].second);
  }
}
int main(void){
  input();
  sazmi();
  solve();
  scanf("\n");
  return 0;
}
