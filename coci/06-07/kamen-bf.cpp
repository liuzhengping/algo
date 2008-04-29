#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
long long sol;
vector<int> a[26];
int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; ++i) {
    char s[2]; int x = i;
    scanf("%s%d", &s, &x);
    a[ s[0]-'A' ].push_back(x);
  }
  for(int i = 0; i < 26; ++i)
    if(a[i].size() > 1)
      sort(a[i].begin(), a[i].end(), greater<int>());
    
  for(int i = 0; i < m; ++i) {
    char s[2];
    scanf("%s", &s);
    if( a[ s[0]-'A' ].empty() ) { sol = -1; break; }
    sol += a[ s[0]-'A' ].back();
    a[ s[0]-'A' ].pop_back();
  }
  printf("%lld\n", sol);
  return 0;
}