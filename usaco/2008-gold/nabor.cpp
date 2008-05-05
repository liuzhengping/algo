/*
PROG: nabor
LANG: C++
ID: leden.o1
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define FC(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define MAX 100005
using namespace std;
int n, r, comp, max_comp;
struct point {
  int x, y, id;
  point(int x, int y, int id = -1) : x(x), y(y), id(id) { }
  point() { x = y = -1; }
};
struct cmpx {
  bool operator()(const point& a, const point& b) const {
    if(a.x < b.x) return true;
    if(a.x > b.x) return false;
    return a.y < b.y;
  }
};
struct cmpy {
  bool operator()(const point& a, const point& b) const {
    if(a.y < b.y) return true;
    if(a.y > b.y) return false;
    if(a.x < b.x) return true;
    if(a.x > b.x) return false;
    return a.id < b.id;
  }
};
vector<point> v;
queue<point> q;
set<point, cmpy> s;
set<point, cmpy>::iterator wh[MAX];
struct node {
    int cnt, id, h;
    node *dad;
    node() { dad = NULL; cnt = 1; id = -1; h = 0; }
    friend bool operator<(const node& a, const node& b) {
      return a.id < b.id;
    }
};
vector<node> distinct;
struct union_find {
  node t[MAX];
  node get_dad(int a) {
    node* dada;
    for(dada = &t[a]; dada->dad != NULL; dada = dada->dad) ;
    return *dada;
  }
  void merge(int a, int b) {
    if(a == b) return ;
    node *dada, *dadb, *last, *curr;
    for(dada = &t[a]; dada->dad != NULL; dada = dada->dad) ;
    for(dadb = &t[b]; dadb->dad != NULL; dadb = dadb->dad) ;
    if(dada == dadb) return ;
    if(dada->h < dadb->h) {
      dada->dad = dadb;
      dadb->cnt += dada->cnt;
    }
    else {
      if(dada->h == dadb->h) ++dada->h;
      dadb->dad = dada;
      dada->cnt += dadb->cnt;
    }
  }
  union_find() {
    for(int i = 0; i < MAX; ++i)
      t[i].id = i;
  }
} uf;
void greska() { 
  for(;;) q.pop(); 
}
void solve() {
  sort(v.begin(), v.end(), cmpx());
  FC(it, v) {
    for(; !q.empty() && q.front().x < it->x - r; q.pop())
      s.erase( wh[q.front().id] );
    if(!s.empty()) { 
      set<point, cmpy>::iterator lo = s.lower_bound( point(0, it->y-r, -1) );
      set<point, cmpy>::iterator hi = s.lower_bound( point(0, it->y+r+1, -1) );
      if(hi != s.begin() && lo != s.end()) {
        
//         for(set<point, cmpy>::iterator i = lo; i != hi; ++i)
//           uf.merge(i->id, it->id);
        //ako maknem ovo komentirano onda ima premalo komponenti, tj vise ih spoji
        --hi; 
        uf.merge(lo->id, it->id); //merge it into one
        uf.merge(hi->id, it->id); //merge it into one
      
      }
    }
    wh[it->id] = s.insert(*it).first;
    q.push(*it);
  }
  
  for(int i = 0; i < n; ++i) {
    node dad = uf.get_dad(i);
    distinct.push_back(dad);
    max_comp >?= dad.cnt;
  }
  sort(distinct.begin(), distinct.end());
  int k;
  for(int i = 0; i < distinct.size(); i = k) {
    for(k = i+1; k < distinct.size() && distinct[i].id == distinct[k].id; ++k) ;
    ++comp;
  }
}
void output() {
  FILE *out = fopen("nabor.out", "w");
  fprintf(out, "%d %d\n", comp, max_comp);
  printf("%d %d\n", comp, max_comp);
}
void input() {
  FILE *in = fopen("nabor.in", "r");
  fscanf(in, "%d%d", &n, &r);
  for(int i = 0; i < n; ++i) {
    int x, y;
    fscanf(in, "%d%d", &x, &y);
    v.push_back( point(x+y, x-y, i) );
  }
}
int main() {
  input();
  solve();
  output();
  return 0;
}
