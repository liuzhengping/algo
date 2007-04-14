#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int n, sol;
struct point {
  int x, y;
  int k;
  point() {}
  point(const int& X, const int& Y, const int& K) {x=X; y=Y; k=K;}  
};
struct compx {
  bool operator()(const point&a, const point& b) {
    if(a.x != b.x) return a.x < b.x;
    return a.k < b.k;
  }
} pox;
struct prav {
  point a, b;
  prav() {}
  prav(const point& A, const point& B) {a=A; b=B;}
};
struct comp {
  bool operator()(const point& p1, const point& p2) {
    if(p1.y != p2.y) return p1.y < p2.y;
    return p1.k < p2.k; // prednost ima krajnja tocka prav.
  }  
}; 
vector<point> v;
vector<prav> p;
set<point, comp> s;
int sweep() {
  //radi sweep line vertikalno i gleda gdje je najvise pravokutnika koji se sijeku
  int curr = 0, best = 0;
  for(set<point>::iterator it = s.begin(); it != s.end(); ++it) { 
    if(it->k > 0) ++curr;
    else --curr;
    best >?= curr;
  }
  return best;  
}   
void solve() {
  sort(v.begin(), v.end(), pox);
  for(int i = 0; i < v.size(); ++i) {
    int koji = v[i].k;
    //ako je prav. koji upravo usao ubaci ga u set
    if(koji > 0) {
      s.insert(p[koji].a);
      s.insert(p[koji].b);
      
      sol >?= sweep();
    }
    //ako je prav. koji izasao izbaci ga iz seta  
    else {
      koji = -koji;
      s.erase(p[koji].a);
      s.erase(p[koji].b);
    }
  }
  printf("%d", sol);  
}  
void input() {
  scanf("%d", &n);
  p.resize(n+1);
  for(int i = 1; i <= n; ++i) {
    int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
    v.push_back(point(a, b, i));
    v.push_back(point(c, d, -i));
    p[i] = prav(point(a, b, i), point(c, d, -i));
  }
}
int main() {
  input();
  solve();
  scanf("\n");
  return 0;
}  
/*
http://www.topcoder.com/tc?module=Static&d1=tutorials&d2=lineSweep
6
0 0 4 3
2 2 10 5
5 1 7 8
6 7 8 9
1 15 9 18
8 8 12 17
*/
