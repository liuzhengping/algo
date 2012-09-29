#include <cstdio>
#include <cstring>

#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <vector>

#define x first
#define y second

#define SQ(x) ((x)*(x))

using namespace std;

typedef pair<int, int> point_t;

struct target_t {
  virtual bool inside(point_t p) = 0;
};

struct rect_t : target_t {
  point_t p1, p2;
  rect_t(point_t p1, point_t p2) : p1(p1), p2(p2) {}
  bool inside(point_t p) {
    return p1.x <= p.x && p.x <= p2.x &&
      p1.y <= p.y && p.y <= p2.y;
  }
};

struct circle_t : target_t {
  point_t s;
  int r;
  circle_t(point_t s, int r) : s(s), r(r) {}
  bool inside(point_t p) {
    return SQ(p.x - s.x) + SQ(p.y - s.y) <= SQ(r);
  }
};

target_t* read_target() {
  char s[15];
  point_t p1, p2; int r;
  scanf("%s%d%d", s, &p1.x, &p1.y);
  if (strcmp(s, "rectangle") == 0) {
    scanf("%d%d", &p2.x, &p2.y);
    return new rect_t(p1, p2);
  }
  scanf("%d", &r);
  return new circle_t(p1, r);
}

int main() {
  int m, n;
  scanf("%d", &m);
  vector<target_t*> a(m);
  for (int i = 0; i < m; ++i)
    a[i] = read_target();

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    point_t p;
    scanf("%d%d", &p.x, &p.y);
    int hit_cnt = 0;
    for (int j = 0; j < m; ++j)
      hit_cnt += a[j]->inside(p);
    printf("%d\n", hit_cnt);
  }
  return 0;
}
