#include <cstdio>
#include <iostream>
#define MAX 100005
using namespace std;
int n, fx[MAX], fy[MAX], p[MAX][2];
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d%d", &p[i][0], &p[i][1]);
    ++fx[p[i][0]];
    ++fy[p[i][1]];
  }  
  long long sol = 0;
  for(int i = 0; i < n; ++i)  
    sol += (long long) (fx[p[i][0]]-1)*(fy[p[i][1]]-1);
  printf("%lld", sol);
  scanf("\n");
  return 0;
}


