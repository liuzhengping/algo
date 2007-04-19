#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define MAX 100002
using namespace std;
int n, sol[MAX], sum;
struct daske {
  int l, cost;
  int br;
  daske() {}
  daske(int a, int b, int c) {
    l = a; cost = b; br = c;
  }  
};
bool operator<(const daske& a, const daske& b) {
  return a.cost > b.cost;
}   
vector<daske> d;  
set<pair<int, int> > c;  
void solve() {
  sort(d.begin(), d.end());
  set<pair<int, int> >::iterator it;
  for(int i = 0; i < n; ++i) {
    it = c.lower_bound(make_pair(d[i].l, 0));
    if(it == c.end()) --it;
    else if(it->first > d[i].l) {
      if(it == c.begin()) {
        it = c.end();
        --it;
        sol[d[i].br] = it->second; 
        c.erase(it);
        continue;
      }  
      --it;
    } 
    sol[d[i].br] = it->second;
    c.erase(it);
    sum+=d[i].cost;
  }
  printf("%d\n", sum);
  for(int i = 0; i < n; ++i) printf("%d ", sol[i]+1);  
}  
void input() {
  scanf("%d", &n);
  d.resize(n);
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    c.insert(make_pair(x, i));
  }  
  for(int i = 0; i < n; ++i) {
    int a, b; scanf("%d%d", &a, &b);
    d[i] = daske(a, b, i);
  }  
}  
int main() {
  input();
  solve();
  scanf("\n");
  return 0;
}  
/*
5
400 200 500 600 400
200 400
300 600
400 200
500 800
600 100
*/
