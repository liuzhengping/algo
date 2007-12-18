#include <cstdio>
#include <iostream>
using namespace std;
int a[1000000], n, k, len;
struct stablo {
  int tree[4200000];
  int offset;
  int get(int x) {
    int pos;
    ++x;
    for(pos = 1; pos < 2*offset; ) {
      if(x <= tree[2*pos])
        pos = 2*pos;
      else {
        x -= tree[2*pos];
        pos = 2*pos+1;
      }
    }
    return pos/2 - offset;
  }
  void erase(int pos) {
    for(pos = get(pos) + offset; pos > 0; pos /= 2)
      --tree[pos];
  }
  void insert(int pos) {
    pos += offset;
    tree[pos] = 1; //moglo je i tree[pos += offset] = 1;
    for(pos /= 2; pos > 0; pos /= 2)
      tree[pos] = tree[2*pos] + tree[2*pos+1];
  }
  void construct() {
    len = n;
    for(int i = 0; i < n; ++i) a[i] = i+1;
    for(offset = 1; offset < n; offset *= 2) ; // ili { }
    for(int i = 0; i < n; ++i) insert(i);
  }
} st; //ili jednostavno: stablo st;
int solve() {
  for(int pos = -1; len > 1; ) {
    pos = (pos+k) % len;
    st.erase(pos);
    pos = (pos+ --len - 1) % len;
  }
  for(int i = 0; i < n; ++i)
    if(st.tree[i+st.offset] > 0)
      return a[i];
}
int main() {
  printf("Enter n (number of elements): "); scanf("%d", &n);
  printf("Enter k (every k-th will be erased): "); scanf("%d", &k);
  st.construct();
  printf("Last remaining: %d\n", solve());
  scanf("\n");
  return 0;
}
