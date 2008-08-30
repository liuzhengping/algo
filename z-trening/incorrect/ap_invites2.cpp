#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <deque>
using namespace std;
int n, m;
set<unsigned> inv;
map<unsigned, int> freq;
deque<unsigned> d;
unsigned hash(const char* s) {
  unsigned ret = 0;
  int len = strlen(s);
  for(int i = 0; i < len; ++i)
    ret = (ret + s[i]-'0') * 29;
  return ret;
}
int main() {
  int sol = 1000000000, cnt = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    char buff[25];
    scanf("%s", &buff);
    inv.insert( hash(buff) );
  }
  n = (int) inv.size();
  scanf("%d", &m);
  for(int i = 0; i < m; ++i) {
    char buff[25];
    scanf("%s", &buff);
    unsigned hb = hash(buff);
    d.push_back(hb);
    if( inv.find(hb) == inv.end() ) continue;
    if(freq[hb]++ == 0) ++cnt;
    for(; !d.empty() && (!freq.count(d.front()) || freq[ d.front() ] > 1); d.pop_front())
      if( inv.find(d.front()) != inv.end() )
	--freq[ d.front() ];
    if(cnt == n) sol = min(sol, (int) d.size());
  }
  printf("%d\n", sol);
  return 0;
}
