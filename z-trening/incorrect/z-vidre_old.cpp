#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
#define FC(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define MAX 405
using namespace std;
int n, m, source, sink;
int used[MAX], bio[MAX], pred[MAX];
struct edge { 
  int a, b, w; 
  edge(int a, int b, int w):a(a),b(b),w(w) {} 
  edge() {}
};
vector<edge> e;
vector<vector<pair<int, int> > > adj;
void input() {
  scanf("%d%d", &m, &n);
  source = n;
  sink = n+1;
  n += 2;
  for(int i = 0; i < m; ++i) {
    int a, b, w;
    scanf("%d%d%d", &w, &a, &b);
    --a; --b;
    e.push_back( edge(a, b, w) );
    e.push_back( edge(b, a, w) );
  }
  int source_e, sink_e;  
  scanf("%d", &source_e);
  for(int i = 0; i < source_e; ++i) {
    int a;
    scanf("%d", &a);
    --a;
    e.push_back( edge(source, a, 0) );
  }  
  scanf("%d", &sink_e);
  for(int i = 0; i < sink_e; ++i) {
    int a;
    scanf("%d", &a);
    --a;
    e.push_back( edge(a, sink, 0) );
  } 
}
void construct(int w) {
  adj.clear();
  adj.resize(n);
  FC(it, e)
    if(it->w <= w)
      adj[it->a].push_back( make_pair( it->b, it->w) );
} 
bool bfs() {
  memset(pred, -1, sizeof pred);
  memset(bio, 0, sizeof bio);
  queue<int> q;
  bio[source] = 1;
  int found = 0;
  for(q.push(source); !q.empty(); q.pop()) {
    int x = q.front();
    if(x == sink) {
      found = 1;
      break;
    }  
    FC(it, adj[x])
      if(!bio[it->first] && !used[it->first]) {
        bio[it->first] = 1;
        pred[it->first] = x;
        q.push(it->first);
      }  
  }  
  if(!found) return false;
  for(int node = pred[sink]; node != source; node = pred[node])
    used[node] = 1;  
  return true; 
}      
int flow() {
  memset(used, 0, sizeof used);
  int ret = 0;
  while( bfs() )
    ++ret;
  return ret;
}  
int solve() {
  int sol = 10005;
  construct(10005);
  int maxflow = flow();
  if(maxflow == 0) return 0;
  int lo = 0, hi = 10005, mid;
  for(int itr = 0; itr < 25; ++itr) {
    mid = (lo + hi)/2;
    construct(mid);
    int curr = flow();
    if( curr == maxflow ) {
      hi = mid;
      sol = mid;
    }
    else lo = mid;   
  }
  return sol;
}
int main() {
  input();
  printf("%d", solve());
  scanf("\n");
  return 0;
}
/*
Test 1	Tacno resenje	 vreme izvrsavanja programa 0.01 sekunde
Test 2	Pogresno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 3	Tacno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 4	Tacno resenje	vreme izvrsavanja programa 0 sekunde
Test 5	Tacno resenje	vreme izvrsavanja programa 0 sekunde
Test 6	Tacno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 7	Pogresno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 8	Pogresno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 9	Sistemska greska ili prekoracen memorijski limit
Test 10	Tacno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 11	Sistemska greska ili prekoracen memorijski limit
Test 12	Tacno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 13	Tacno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 14	Pogresno resenje	vreme izvrsavanja programa 0 sekunde
Test 15	Tacno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 16	Tacno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 17	Tacno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 18	Tacno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 19	Tacno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 20	Sistemska greska ili prekoracen memorijski limit
Test 21	Tacno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 22	Tacno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 23	Tacno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 24	Sistemska greska ili prekoracen memorijski limit
Test 25	Sistemska greska ili prekoracen memorijski limit
Test 26	Pogresno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 27	Pogresno resenje	vreme izvrsavanja programa 0 sekunde
Test 28	Pogresno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 29	Tacno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 30	Tacno resenje	vreme izvrsavanja programa 0.02 sekunde
Test 31	Pogresno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 32	Tacno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 33	Tacno resenje	vreme izvrsavanja programa 0.02 sekunde
Test 34	Tacno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 35	Tacno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 36	Pogresno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 37	Pogresno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 38	Tacno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 39	Pogresno resenje	vreme izvrsavanja programa 0.02 sekunde
Test 40	Pogresno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 41	Tacno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 42	Sistemska greska ili prekoracen memorijski limit
Test 43	Sistemska greska ili prekoracen memorijski limit
Test 44	Pogresno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 45	Tacno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 46	Pogresno resenje	vreme izvrsavanja programa 0.01 sekunde
Test 47	Tacno resenje	vreme izvrsavanja programa 0.02 sekunde
Test 48	Sistemska greska ili prekoracen memorijski limit
Test 49	Tacno resenje	vreme izvrsavanja programa 0.06 sekunde
Test 50	Tacno resenje	vreme izvrsavanja programa 0.01 sekunde
*/

