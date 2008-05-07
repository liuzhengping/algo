#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1005
using namespace std;
int n; const int inf = 1000000000;
struct point {
  int x, y;
  point() { }
  point(int x, int y) : x(x), y(y) { }
} a[MAX], anchor;
int ccw(const point& A, const point& B, const point& C) {
  return A.x*(B.y-C.y) + B.x*(C.y-A.y) + C.x*(A.y-B.y);
}
struct cmp {
  bool operator()(const point &a, const point& b) {
    return ccw(anchor, A, B) >= 0;
  }
};
void convex() {
  anchor = point(inf, inf);
  for(int i = 0; i < n; ++i) {
    if(a[i].y < anchor.y || a[i].y == anchor.y && a[i].x < anchor.x) {
      anchor = a[i];
    }
  }
  a[n] = a[0];
  
  s.push_back(a[0]);
  s.push_back(a[1]);
  for(;;) {
    
  }

  sort(a, a+n, cmp());
}
void input() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i].x, &a[i].y);
  }
}
int main() {
  input();
  return 0;
}
