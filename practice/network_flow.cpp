#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#define FC(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define MAX 205
using namespace std;
const int inf = 1000000000;
int n, m, source, sink;
vector< vector<int> > adj;
int cap[MAX][MAX], bio[MAX], pred[MAX];
int augment() {
  memset(pred, -1, sizeof(pred));
  memset(bio, 0, sizeof(bio));
  queue<int> q;
  for(q.push(source); !q.empty(); q.pop() ) {
    int u = q.front();
    if(u == sink) break;
    FC(it, adj[u]) {
      if(!bio[*it] && cap[u][*it] > 0 ) {
        bio[*it] = 1;
        pred[*it] = u;
        q.push(*it);
      }
    }
  }
  int maxflow = inf;
  for(int curr = sink; pred[curr] != -1; curr = pred[curr])
    maxflow <?= cap[ pred[curr] ][ curr ];
  if(maxflow == inf) return 0;
  for(int curr = sink; curr != source; curr = pred[curr]) {
    cap[ pred[curr] ][ curr ] -= maxflow;
    cap[ curr ][ pred[curr] ] += maxflow;
  }
  return maxflow;
}
int network() {
  int ret = 0;
  while(true) {
    int flow = augment();
    if(!flow) break;
    ret += flow;
  }
  return ret;
}
vector< vector<int> > transform( int _n, vector< vector<int> > E, vector<int> start, vector<int> end ) {
   vector<int> end2( _n );
   vector< vector<int> > ret( _n );
   vector<int> bio( _n );
   queue<int> Q;

   for( int i = 0; i < (int)start.size(); ++i ) 
      Q.push( start[i] );
   for( int j = 0; j < (int)end.size(); ++j ) 
      end2[ end[j] ] = 1;
   
   for( ; !Q.empty(); Q.pop() ) {
      int V = Q.front();
      for( int i = 0; i < (int)E[V].size(); ++i ) {
         if( !bio[ E[V][i] ] ) {
            bio[ E[V][i] ] = 1;
            ret[V].push_back( E[V][i] );
            if( !end2[ E[V][i] ] ) Q.push( E[V][i] );
         }
      }
   }
   
   return ret;
}
void input() {
  scanf("%d%d", &n, &m);
  scanf("%d%d", &source, &sink);
  --source; --sink;
  adj.resize(n);
  for(int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    --a; --b;
    cap[a][b] = 1;
    adj[a].push_back(b);
    //adj[b].push_back(a);
  }
  
}
int main() {
  input(); printf("ok");
  
  //printf("Prije: %d\n", network() );
  
  vector<int> v_start, v_end;
  v_start.push_back(source);
  v_end.push_back(sink);
  //adj = transform(n, adj, v_start, v_end);
  n = adj.size();
  memset(cap, 0, sizeof(cap));
  for(int i = 0; i < n; ++i)
    FC(it, adj[i])
      cap[i][*it] = 1;
  
  
  printf("Poslije: %d\n", network() );
  printf("GOTOVO\n\n");
  return 0;
}

/*
6 8
5 2
5 1 9
5 4 4
4 1 5
4 6 7
1 3 5
3 2 2
3 6 6
6 2 8
*/  
