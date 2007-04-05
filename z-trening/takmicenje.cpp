#include <iostream>
#include <cstdio>
#define MAX 1000005
using namespace std;
int n, k, x, last_poc, poc_bod, poc_n, bod[MAX], last[MAX];
int curr = 1;
bool radi() {
  scanf("%d", &k);
  if(k == 3) return false;
  if(k == 0) {
    last_poc = curr;
    scanf("%d%d", &n, &x);
    poc_bod = x;
  }
  else if(k == 1) {
    int x, y;
    scanf("%d%d", &x, &y);
    if(last[x] < last_poc) bod[x] = poc_bod;
    bod[x] += y;
    last[x] = curr;
  }
  else if(k == 2) {
    int x;
    scanf("%d", &x);
    if(last[x] < last_poc) bod[x] = poc_bod;
    printf("%d\n", bod[x]);
  }      
  return true;
}  
int main() {
  for(;radi(); ++curr) ;
  return 0;
}  
