#include <cstdio>
#include <cmath>
#include <iostream>
#define MAX 10
using namespace std;
double a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
int n1, n2, m1, m2;
void input() {
  scanf("%d %d", &n1, &m1);
  for(int i = 0; i < n1; ++i)
    for(int j = 0; j < m1; ++j)
      scanf("%lf", &a[i][j]);
  scanf("%d %d", &n2, &m2);
  for(int i = 0; i < n2; ++i)
    for(int j = 0; j < m2; ++j)
       scanf("%lf", &b[i][j]);
}
void ispis() {
  for(int i = 0; i < n1; ++i) {
    printf("|");
    for(int j = 0; j < m2; ++j)
      printf("%5.1lf", c[i][j]);
    printf("|\n");
  }  
}  
void solve() {
  for(int i = 0; i < n1; ++i)
    for(int j = 0; j < m2; ++j) {
      for(int k = 0; k < m1; ++k) {
        //printf(" + %d", a[i][k]*b[k][j]);
        c[i][j] += a[i][k]*b[k][j];
      }   
      //printf(" = %d\n", c[i][j]);
    }  
}    
int main() {
  input();
  solve();
  ispis();
  scanf("\n");
  return 0;
}
/*
3 4
1.0  0.3 -0.7  3.7
0.0  1.0 -1.0  8.0
0.0  0.0  1.0 -1.5

4 2
1 5
2 3
6 2
7 3

3 4
2 1 -1 8
0 .5 .5 1
0 0 -1 1

4 2
1 5
2 3
6 2
7 3

*/


