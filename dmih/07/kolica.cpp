#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#define MAX 505
using namespace std;
const int dxy[4][2] = {1,0,0,1,-1,0,0,-1};
int n, bio[MAX];
struct kolica {
  int x, y, sm;
  int br;
  int vr;
  kolica() {}
  kolica(int X, int Y, int SM, int BR) {x=X; y=Y; sm=SM; br=BR;}
};
struct cmp {
  bool operator()(const kolica& a, const kolica& b) {
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
  }  
} mojsort;
struct event {
  kolica a, b;
  int vr;
  event() {}
  event(const kolica& A, const kolica& B, int VR) {
    a = A; b = B; vr = VR;
  }  
};
vector<event> e;
struct cmp2 {
  bool operator()(const event& a, const event& b) {
    return a.vr < b.vr;
  }  
} povr;
vector<kolica> v; 
bool kv(int x1, int y1, int x2, int y2) {
  return abs(x1-x2) == abs(y1-y2);
}  
void solve() {
  sort(v.begin(), v.end(), mojsort);
  for(int i = 0; i < n-1; ++i)
    for(int j = i+1; j < n; ++j) {
      if(v[i].x == v[j].x) {
        if(v[i].y < v[j].y) {
          if(v[i].sm == 1 && v[j].sm == 3)
            e.push_back(event(v[i], v[j], v[j].y-v[i].y));
        }
        else e.push_back(event(v[i], v[j], v[i].y-v[j].y)); 
      }  
      else if(v[i].y == v[j].y) {
        if(v[i].sm == 0 && v[j].sm == 2)
          e.push_back(event(v[i], v[j], v[j].x-v[i].x));
      }  
      else if(kv(v[i].x, v[i].y, v[j].x, v[j].y)) {
        if(v[i].y < v[j].y) {
          if(v[i].sm == 0 && v[j].sm == 3)
            e.push_back(event(v[i], v[j], 2*abs(v[i].x - v[j].x)));
          else if(v[i].sm == 1 && v[j].sm == 2)
            e.push_back(event(v[i], v[j], 2*abs(v[i].x - v[j].x)));
        }
        else {
          if(v[i].sm == 0 && v[j].sm == 1)
            e.push_back(event(v[i], v[j], 2*abs(v[i].x - v[j].x)));
          else if(v[i].sm == 3 && v[j].sm == 2)
            e.push_back(event(v[i], v[j], 2*abs(v[i].x - v[j].x)));
        }    
      }  
    }
  sort(e.begin(), e.end(), povr);
  int curr, k;
  for(curr = 0; curr < e.size(); curr = k) {
    for(k = curr+1; k < e.size() && e[k].vr == e[k-1].vr; ++k) ;
    for(int i = curr; i < k; ++i) {
      if((bio[e[i].a.br] && bio[e[i].a.br] != e[curr].vr)
       || (bio[e[i].b.br] && bio[e[i].b.br] != e[curr].vr)) continue;
      bio[e[i].a.br] = e[curr].vr;
      bio[e[i].b.br] = e[curr].vr;
    }  
  }    
}
void output() {
  int ok = 0;
  for(int i = 0; i < n; ++i)
    if(!bio[i]) {ok = 1; printf("%d\n", i+1);}
  if(!ok) printf("nema");
}    
void input() {
  scanf("%d", &n);
  v.resize(n);
  for(int i = 0; i < n; ++i) {
    int x, y, sm; char s[15];
    scanf("%d%d%s", &x, &y, &s);
    if(strcmp(s, "desno") == 0) sm = 0;
    else if(strcmp(s, "gore") == 0) sm = 1;
    else if(strcmp(s, "lijevo") == 0) sm = 2;
    else sm = 3;
    v[i] = kolica(x,y,sm, i);
  }  
}  
int main() {
  input();
  solve();
  output();
  scanf("\n");
  return 0;
} 
/*
4
5 5 dolje
5 6 lijevo
5 7 desno
5 8 gore

5
3 3 dolje
1 1 desno
5 1 lijevo
100000 500000 desno
900000 500000 lijevo

3
10 0 gore
0 10 desno
15 5 lijevo
*/ 
