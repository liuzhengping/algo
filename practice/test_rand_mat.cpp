#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
//char var[61] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&/()";
int main() {
  srand(time(0));
  int n = 58;
  printf("%d\n", n);
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      int r = rand()%15;
      int pred = rand()&1;
      if(pred) printf("-");
      else printf("+");
      printf("%d%c", r, 'A'+j);
    }
    printf("=%d\n", rand()%50 - 25);
  } 
  return 0;
}


