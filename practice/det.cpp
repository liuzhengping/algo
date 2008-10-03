#include <cstdio>
#include <cmath>
#include <iostream>
#define EPS 1e-12
#define MAX 105
using namespace std;
struct mat {
  int n;
  double a[MAX][MAX];
  void addrow(int r1, int r2, double x) {
    for(int i = 0; i < n; ++i)
      a[r1][i] += a[r2][i]*x;
  }
  void swaprows(int r1, int r2) {
    int tmp[MAX];
    memcpy(tmp, a[r1], sizeof(tmp));
    memcpy(a[r1], a[r2], sizeof(tmp));
    memcpy(a[r2], tmp, sizeof(tmp));
  }
  void doswap(int r) {
    for(int i = r+1; i < n && fabs(a[r][r]) < EPS; ++i)
      swaprows(r, i);
  }
  double find_det() {
    mat backup = *this;
     doswap(0);
     for(int r = 1; r < n; ++r) {
       doswap(r);
       for(int c = 0; c < r; ++c)
         addrow(r, c, -a[r][c]/a[c][c]);
     }
     double ret = 1;
     for(int i = 0; i < n; ++i)
       ret *= a[i][i];
     *this = backup;
     return ret;
  }
  void output() {
    for(int i = 0; i < n; ++i, printf("\n") )
      for(int j = 0; j < n; ++j)
	printf("%5.2lf", a[i][j]); 
    printf("\n");
  }
  void input() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
	scanf("%lf", &a[i][j]);
  }
  mat() { 
    memset(a, 0, sizeof(a)); 
    for(int i = 0; i < n; ++i) a[i][i] = 1;
  }
  friend mat operator+(mat A, const mat& B) {
    for(int i = 0; i < A.n; ++i)
      for(int j = 0; j < A.n; ++j)
	A.a[i][j] += B.a[i][j];
    return A;
  } 
  friend mat operator*(const mat& A, const mat& B) {
    mat C;
    memset(C.a, 0, sizeof(C.a));
    for(int i = 0; i < A.n; ++i)
      for(int j = 0; j < A.n; ++j)
	for(int k = 0; k < A.n; ++k)
	  C.a[i][j] += A.a[i][k] * B.a[k][j];
    return C;
  }
} d;
  

int main() {
  d.input();
  printf("Det(d) = %lf\n", d.find_det());
  d.output();
  
  return 0;
}
