#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
typedef long long LL;
LL x, MOD, A, B, sol;
char bio[1000005];
int pot(LL a, LL k) {
  LL curr = a, ret = 1;
  for(int i = 0; i < 62; ++i, curr = (curr*curr)%MOD)
    if((1LL << i) & k)
      ret = (ret*curr)%MOD;
  return ret;
}  
int main() {
  cin >> x >> MOD >> A >> B;
  for(LL i = B; i >= A; --i) {
    LL curr = pot(x, i);
    sol = max(sol, curr);
    if(bio[curr]) break;
    bio[curr] = 1;
  }
  cout << sol << endl;
  scanf("\n");
  return 0;
}


