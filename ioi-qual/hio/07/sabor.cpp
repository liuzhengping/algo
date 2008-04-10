#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 2005
#define OFF 1003
using namespace std;
typedef long long LL;
int n, k, dist[MAX][MAX];
const pair<int, int> dxy[4] = {make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0)};
LL sol[2];
pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) { 
  return make_pair(a.first+b.first, a.second+b.second); 
}
bool ok(const pair<int, int>& a) {
  return a.first >= 0 && a.first < MAX && a.second >= 0 && a.second < MAX; 
} 

void special(int x) {
  if(x >= n || x < 0) return ;
  LL even = n/2 - x/2;
  LL odd = (n-x) - (n/2-x/2);
  if(x%2) {
    sol[1] += (LL) (odd+1)*(odd+1)-1;
    sol[0] += (LL) even*(even+1);
  }  
  else {
    sol[1] += (LL) odd*(odd+1);
    sol[0] += (LL) (even+1)*(even+1)-1;
  }  
}  
void add(int x) {
  if(x >= n || x < 0) return ;
  sol[0] += n/2 - x/2;
  sol[1] += (n-x) - (n/2-x/2);
}  
void solve() {
  queue<pair<int, int> > q; 
  dist[OFF][OFF] = 0;
  for(q.push(make_pair(OFF, OFF)); !q.empty(); q.pop()) {
    pair<int, int> u = q.front();
    if(dist[u.first][u.second] <= n)
      ++sol[ dist[u.first][u.second]%2 ];
    for(int i = 0; i < 4; ++i) {
      pair<int, int> np = u + dxy[i];
      if(!ok(np)) continue;
      if(dist[np.first][np.second] == -1) {
        dist[np.first][np.second] = dist[u.first][u.second] + 1;
        q.push(np);
      }  
    }  
  }
  for(int i = 1; i < MAX-1; ++i) {
    add(dist[i][0]);
    add(dist[i][MAX-1]);
  }  
  for(int i = 1; i < MAX-1; ++i) {
    add(dist[MAX-1][i]);
    add(dist[0][i]);
  }
  special(dist[0][0]);
  special(dist[0][MAX-1]);
  special(dist[MAX-1][0]);
  special(dist[MAX-1][MAX-1]);
  cout << sol[0] << " " << sol[1] << endl;  
}  
void input() {
  memset(dist, -1, sizeof dist);
  scanf("%d%d", &k,&n);
  for(int i = 0; i < k; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    dist[a+OFF][b+OFF] = -2;
  }  
}  
int main() {
  input();
  solve();
  return 0;
}  
