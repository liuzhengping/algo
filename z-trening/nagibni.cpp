#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2002
using namespace std;
typedef vector<pair<int, int> >::iterator viter;
const int inf = 1000000000;
const int undef = - (inf + 1);
vector<vector<pair<int, int> > > adj;
int n, memo[MAX][2];
int rek(int x, int dad, int stanje) {
  if(memo[x][stanje] != undef) return memo[x][stanje];
  int best1 = -inf, best2 = -inf, ret = -inf, sum = 0;
  for(viter it = adj[x].begin(); it != adj[x].end(); ++it) {
    if(it->first == dad) continue;
    int sa = rek(it->first, x, 1) + it->second;
    int bez = rek(it->first, x, 0);
    sum += bez;
    if(sa - bez > best1) {
      best2 = best1;
      best1 = sa - bez;
    }
    else if(sa - bez > best2) best2 = sa - bez;  
  }  
  if(stanje) //uzimam bolje od (da li linije zavrsava ) i (da li linija prolazi)
    ret >?= max(sum, sum + best1);
  else //uzimam bolje od (da li linija prolazi) i (da li linija pocinje ovdje) 
    ret >?= max(sum + best1 + best2, sum + best1);
  return memo[x][stanje] = ret;
}  
void solve() {
  for(int i = 0; i < n; ++i)
    memo[i][0] = memo[i][1] = undef;
  printf("%d", rek(0, -1, 0));
}  
void input() {
  scanf("%d", &n);
  adj.resize(n);
  for(int i = 0; i < n-1; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c); --a; --b;
    adj[a].push_back(make_pair(b, c));
    adj[b].push_back(make_pair(a, c));
  } 
}  
int main() {
  input();
  solve();
  return 0;
}  
