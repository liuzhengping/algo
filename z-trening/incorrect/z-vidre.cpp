#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm>
#define FC(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define MAX 805
using namespace std;
typedef pair<int, int> par;
const int inf = 1000000000;
int n, m, source, sink, sol;
int cap[MAX][MAX], h[MAX], bio[MAX], pred[MAX];
vector< vector<par> > adj;
string uredi(int x) {
  ostringstream os;
  if(x == source) os << "source";
  else if(x == sink) os << "sink";
  else if(x&1) os << (x/2) << ">";
  else os << ">" << x/2;
  return os.str();
}
void debug() {
  for(int i = 0; i < 2*n; ++i) {
    printf("%s\n", uredi(i).c_str());
    FC(it, adj[i])
      printf("(%s %d)", uredi(it->first).c_str(), it->second);
    printf("\n");
  }
}
int path() {
  memset(pred, -1, sizeof(pred));
  memset(bio, 0, sizeof(bio));
  for(int i = 0; i < 2*n; ++i)
    h[i] = inf;
  h[source] = 0;
  while(true) {
    int u = -1, cf = inf;
    for(int i = 0; i < 2*n; ++i) {
      if(!bio[i] && h[i] < cf) {
        cf = h[i];
        u = i;
      }
    }
    
    if(u == -1) break;
    printf("[%d = %d]", u, h[u]);
    if(u == sink) { printf("OVO je sink"); break; }
    bio[u] = 1;
    
    FC(it, adj[u]) {
      if(cap[u][it->first] > 0 && !bio[it->first]) {
        if( h[it->first] > max( h[u], it->second ) ) {
          h[it->first] = max( h[u], it->second );
          printf("[ %s %d ]", uredi(it->first).c_str(), h[it->first] );
          pred[it->first] = u;
        }
      }
    }
  }
  for(int i = 0; i < 2*n; ++i)
    printf("(%d)", h[i]);
  if(h[sink] == inf) return 0;
  int path_cap = inf;
  for(int curr = sink; curr != source; curr = pred[curr])
    path_cap <?= cap[ pred[curr] ][ curr ];
  printf("Found path:\n");
  for(int curr = sink; curr != source; curr = pred[curr]) {
    cap[ pred[curr] ][ curr ] -= path_cap;
    cap[ curr ][ pred[curr] ] += path_cap;
    printf("(%d -> %d)", pred[curr], curr);
    sol >?= h[curr];
  }
  return path_cap;
}
void solve() {
  int br = 0;
  for(;;) {
    if( !path() ) break;
    //sol >?= h[sink];
    ++br;
  }
  if(sol == inf) printf("0\n");
  else printf("%d\n", sol);
  printf("MAXFLOW = %d\n", br);
}
void input() {
  scanf("%d%d", &m, &n);
  ++n;
  source = 0;
  sink = 1;
  adj.resize(n<<1);
  
  for(int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d%d%d", &c, &a, &b);
    adj[(a<<1)+1].push_back( par(b<<1, c) );
    adj[(b<<1)+1].push_back( par(a<<1, c) );
    cap[(a<<1)+1][b<<1] = 1;
    cap[(b<<1)+1][a<<1] = 1;
  }
  
  for(int i = 1; i < n; ++i) {
    adj[i<<1].push_back( par((i<<1)+1, 0) );
    cap[i<<1][(i<<1)+1] = 1;
  }
  
  int k;
  scanf("%d", &k);
  for(int i = 0; i < k; ++i) {
    int x; scanf("%d", &x);
    adj[source].push_back( par(x<<1, 0) );
    cap[source][x<<1] = 1;
  }
  scanf("%d", &k);
  for(int i = 0; i < k; ++i) {
    int x; scanf("%d", &x);
    adj[(x<<1)+1].push_back( par(sink, 0) );
    cap[(x<<1)+1][sink] = 1;
  }
  
}
int main() {
  input();
  //debug();
  solve();
  return 0;
}
