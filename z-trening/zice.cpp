#include <cstdio>
#include <cmath>
using namespace std;
const long long max = 100000000000000LL;
int main() {
  double a, b, best, naz = 1, br, sol; int n = 0;
  scanf("%lf%lf", &a, &b); 
  sol = a; best = abs(a-b);
  for(int i = 1; ; ++i) {
    naz *= 3;
    br = 1;
    for(int j = 0; j <= i; ++j, br*=2) {
      double curr = a*br/naz;
      if(abs(curr-b) < best) {
        best = abs(curr-b);
        n = i;
        sol = curr;
      }  
    }
    br/=2;
    if(a*br/naz < b) break; 
  }
  printf("%d\n%.5lf", n, sol);
  //scanf("\n");
  return 0;
}  
