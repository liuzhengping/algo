#include <cstdio>
#define MAX 100
using namespace std;
int n, a[MAX][MAX], dole[MAX][MAX], gore[MAX][MAX];
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
      gore[i][j] = dole[i][j] = a[i][j];
  }  
  for(int i = 1; i < n; ++i)
    for(int j = 1; j < n; ++j)
      gore[i][j] += gore[i-1][j-1];
  for(int i = n-2; i >= 0; --i)
    for(int j = 1; j < n; ++j)
      dole[i][j] += dole[i+1][j-1];
  int sum = 0, last = 0;
  for(int st = 0; st < n; ++st, printf("\n")) {
    sum = last += dole[0][st];
    for(int j = 0; j < n; ++j) {
      printf("%d ", dole[i][j]);
    }  
  }  
  scanf("\n");
  return 0;
}  
