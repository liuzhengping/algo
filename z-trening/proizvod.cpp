#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int n; long long sol = 1;
  long long mod = 1000000000LL;
  scanf("%d", &n);
  for(int i = 2; i <= n; ++i) {
    sol *= i;
    while(!(sol%10)) sol /= 10;
    sol %= mod;
  } 
  printf("%d", sol%10);
  //scanf("\n");
  return 0;
}  
