#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#define MAX 100
#define FORC(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
int n, m, source, sink, pred[MAX], flow[MAX], bio[MAX];
const int inf = 1000000000;
int adj[MAX][MAX];
//vector<list<pair<int, int> > > adj;
void input() {
  scanf("%d%d", &n, &m);
  scanf("%d%d", &source, &sink);
  --source; --sink;
  for(int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    --a; --b;
    adj[a][b] = c;
    adj[b][a] = c;
    //adj[a].push_back(make_pair(b, c));
  }  
}  
int network() {
  int ret = 0;
  while(true) {
    for(int i = 0; i < n; ++i) {
      bio[i] = 0;
      flow[i] = 0;
      pred[i] = -1;
    }
    flow[source] = inf;
    int u = -1;
    while(true) {
      int maxflow = 0;
      u = -1;
      for(int i = 0; i < n; ++i) {
        if(!bio[i] && flow[i] > maxflow) {
          u = i;
          maxflow = flow[i];
        }  
      }
      if(u == -1) break;
      if(u == sink) break;
      bio[u] = 1;
      for(int i = 0; i < n; ++i) {
        if(adj[u][i] <= 0) continue;
        if(min(maxflow, adj[u][i]) > flow[i]) {
          flow[i] = min(maxflow, adj[u][i]);
          pred[i] = u;
        }   
      }    
    } 
    printf("Put:\n");
    if(u == -1) break;
    int best = flow[sink];
    ret += best;
    for(int curr = sink; curr != source; curr = pred[curr]) {
      //printf("[%d]", curr+1); cin.get();
      adj[curr][pred[curr]] += best;
      adj[pred[curr]][curr] -= best;
    }   
  }
  return ret;  
}  
int main() {
  input();
  printf("%d", network());
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
