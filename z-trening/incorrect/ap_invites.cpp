#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <deque>
using namespace std;
int n, m;
set<string> inv;
map<string, int> freq;
deque<string> d;
int main() {
  int sol = 1000000000, cnt = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    char buff[25];
    scanf("%s", &buff);
    inv.insert(buff);
  }
  n = (int) inv.size();
  scanf("%d", &m);
  for(int i = 0; i < m; ++i) {
    char buff[25];
    scanf("%s", &buff);
    d.push_back(buff);
    if( inv.find(buff) == inv.end() ) continue;
    if(freq[buff]++ == 0) ++cnt;
    for(; !d.empty() && (!freq.count(d.front()) || freq[ d.front() ] > 1); d.pop_front())
      if( inv.find(d.front()) != inv.end() )
	--freq[ d.front() ];
    if(cnt == n) sol = min(sol, (int) d.size());
  }
  printf("%d\n", sol);
  return 0;
}
