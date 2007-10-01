#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <set>
#include <functional>
#include <numeric>
#include <algorithm>
#define FC(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define FC1(it, c, from) for(__typeof((c).begin()) it = from; it != (c).end(); ++it)
#define FC2(it, c, from, to) for(__typeof((c).begin()) it = from; it != to; ++it)
#define CLR(x) memset(x,  0, sizeof (x) )
#define RES(x) memset(x, -1, sizeof (x) )
#define EPS 1e-9
#define MAX 
using namespace std; 
typedef long long LL;
typedef pair<int, int> par; 
bool EQ(const double& a, const double& b) { return fabs(a-b) < EPS; }
struct point { int x, y; point() {} point(int x, int y) : x(x), y(y) {} 
  friend bool operator==(const point& a, const point& b) { return a.x==b.x && a.y==b.y; }
  friend bool operator<(const point& a, const point& b) { return (a.x==b.x)?(a.y<b.y):(a.x<b.x); }
};
inline LL sq_distance(const point& a, const point& b) { 
  return (LL)(a.x-b.x)*(a.x-b.x) + (LL)(a.y-b.y)*(a.y-b.y); 
}
inline double distance(const point& a, const point& b) {
  return sqrt((double) (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}  
struct cmp {
  bool operator()(const int a, const int b) {
    return a < b;
  }  
};



