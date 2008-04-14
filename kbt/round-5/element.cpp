#include <cstdio>
#include <iostream>
using namespace std;
typedef unsigned int UI;
int p, r, q;
struct matrica {
  UI a[3][3];
  friend matrica operator*(const matrica& a, const matrica& b) {
    matrica c;
    for(int i = 0; i < 3; ++i)
      for(int j = 0; j < 3; ++j)
        for(int k = 0; k < 3; ++k)
          c.a[i][j] += (long long) a.a[i][k]*b.a[k][j];
    return c;
  }
  friend matrica operator^(const matrica& a, UI k) {
    matrica ret;
    for(int i = 0; i < 3; ++i) ret.a[i][i] = 1;
    
    matrica curr = a;
    for(int i = 0; i < 32; ++i, curr = curr*curr)
      if((1U << i) & k)
        ret = ret * curr;
    return ret;
  } 
  matrica() {
    memset(a, 0, sizeof a);
  }    
};  
int solve() {
  int n;
  matrica curr;
  scanf("%d%d%d", &curr.a[0][0], &curr.a[0][1], &curr.a[0][2]);
  scanf("%d%d%d", &p, &r, &q);
  scanf("%d", &n);
  if(n <= 3) return curr.a[0][n-1];
  matrica change;
  change.a[0][2] = q;
  change.a[1][0] = 1;
  change.a[1][2] = r;
  change.a[2][1] = 1;
  change.a[2][2] = p;
  change = change ^ (n-3);
  matrica sol = curr * change;
  return sol.a[0][2];
}  
int main() {
  printf("%u\n", solve() );
  scanf("\n");
  return 0;
}


