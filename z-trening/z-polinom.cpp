#include <cstdio>
#include <iostream>
#define MAX 2
using namespace std;
const int inf = 0;
int A, N, MOD;
struct matrica {
  long long p[MAX][MAX];
  int n, m;
  friend matrica power(const matrica& a, int x) {
    matrica b(a), curr(a.n, a.m);
    for(int i = 0; i < 32; ++i, b = b*b)
      if((1 << i) & x) curr = curr*b;
    return curr;
  }  
  friend matrica operator*(const matrica& a, const matrica& b) {
    matrica ret;
    ret.n = a.n; ret.m = b.m;
    for(int i = 0; i < a.n; ++i)
      for(int j = 0; j < b.m; ++j)
        for(int k = 0; k < a.m; ++k) {
          ret.p[i][j] += (a.p[i][k] * b.p[k][j]) % MOD;
          ret.p[i][j] %= MOD;
        }
    return ret;
  }
  friend ostream& operator<<(ostream& o, const matrica& a) {
    for(int i = 0; i < a.n; ++i, o << endl)
      for(int j = 0; j < a.m; ++j) o << a.p[i][j] << " ";
    return o;
  }
  template<typename T>
  matrica(T a, T b, int n2, int m2) {
    int curr = 0;
    n = n2; m = m2;
    if(n == 1)
      for(; a != b; ++a, ++curr) p[0][curr] = *a;
    else
      for(; a != b; ++a, ++curr) p[curr/n][curr%n] = *a;

  }
  matrica(int n2, int m2) {//jedinicna n2*m2
    n = n2; m = m2;
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < m; ++j)
        p[i][j] = (i == j);

  }
  matrica() {
    n = MAX; m = MAX;
    memset(p, 0, sizeof(p));
  }
}; 
int main() {
  scanf("%d%d%d", &A, &N, &MOD);
  int a[2] = {1, 1}, b[4] = {A, 0, 1, 1};
  matrica poc(a, a+2, 1, 2), curr(b, b+4, 2, 2);
  curr = power(curr, N);
  matrica res = poc*curr;
  printf("%d", res.p[0][0]);
  //scanf("\n");
  return 0;
}

