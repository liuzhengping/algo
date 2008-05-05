#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define FC(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define MAX 2005
using namespace std;
char sol[MAX], backup[MAX];
vector< vector<int> > adj;
int n, m;
int comp(int x) { return (x < n) ? x+n : x-n; }
int dfs(int x) {
  int ind = (x < n) ? x : x-n;
  char c = (x >= n) ? 'P' : 'G';
  if(sol[ind]) return sol[ind] == c;
  sol[ind] = c;
  
  FC(it, adj[x])
    if( !dfs(*it) ) return 0;
  return 1;
}
int solve() {
  for(int i = 0; i < n; ++i) {
    if(sol[i]) continue;
    int ok = 0;
    for(int truth = 0; truth < 2; ++truth) {
      memcpy(sol, backup, sizeof(sol));
      if( dfs(truth*n + i) ) {
        memcpy(backup, sol, sizeof(sol));
        ok = 1;
        continue;
      }
    }
    if(!ok) return 0;
  }
  sol[n] = '\0';
  return 1;
}
void input() {
  scanf("%d%d", &n, &m);
  adj.resize(2*n);
  for(int i = 0; i < m; ++i) {
    int a, b; char sa[2], sb[2];
    scanf("%d%s%d%s", &a, &sa, &b, &sb);
    --a; --b;
    if(sa[0] == 'P') a += n;
    if(sb[0] == 'P') b += n;
    adj[comp(a)].push_back(b);
    adj[comp(b)].push_back(a);
  }
}
int main(void) {
  input();
  if( solve() )
    printf("%s\n", sol);
  else printf("-1\n");
  return 0;
}
/*

2
3
1 P 2 G
1 G 2 P
1 P 2 P


3
3
1 P 2 G
2 G 3 P
1 P 3 P

3
6
1 G 2 G
2 G 3 G
1 G 3 G
2 P 3 P
1 G 2 P
1 P 3 G

*/
