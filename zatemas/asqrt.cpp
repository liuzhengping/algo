#include <cstdio>
#include <iostream>
#include <vector>
#define MAX 1000000
using namespace std;
bool not_prime[MAX];
vector<int> primes;
vector<pair<int, int> > pf;
void precompute() {
  for(int i = 2; i*i < MAX; ++i)
    if(!not_prime[i])
     for(int j = i; i*j < MAX; ++j)
       not_prime[i*j] = true;
  for(int i = 2; i < MAX; ++i)
    if(!not_prime[i]) primes.push_back(i);
}
int power(int x, int k) {
  int curr = 1, ret = 1;
  for(int i = 0; i < 32; ++i, curr *= curr)
    if((1 << i) & k) ret *= curr;
  return ret;
}  
void factorize(const int x) {
  pf.clear();
  int i = 0;
  for(int r = x; i < primes.size() && primes[i] <= x; ) {
    if(r % primes[i] == 0) {
      if(pf.size() && pf[pf.size()-1].first == primes[i])
        ++pf[pf.size()-1].second;
      else pf.push_back(make_pair(primes[i], 1));
      r /= primes[i];
    }
    else ++i;  
  }
}    
int main(){
  int n;
  precompute();
  scanf("%d", &n);
  for(int i = 0; i <= n; i+=2){
    if(binary_search(primes.begin(), primes.end(), i)) continue;
    fact(i);
    if(rec(0, 1)-i == i) printf("%d\n", i);
  }
  printf("Gotovo\n");  
  scanf("\n");
  return 0;
}  

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <sstream>
#define MAX_PRIME 10005
using namespace std;
int after;
vector<int> prime;
vector<int> factor;
long long pow10(const int k) {
  long long ret = 1;
  for(int i = 0; i < k; ++i) ret*=10;
  return ret;
}
long long po(const int p, const int k) {
  long long ret = 1;
  for(int i = 0; i < k; ++i) ret*=p;
  return ret;
}
void precompute() {
  static int isprime[MAX_PRIME];
  memset(isprime, 1, sizeof isprime);
  for(int i = 2; i*i < MAX_PRIME; ++i)
    if(isprime[i])
      for(int j = 2; j*i < MAX_PRIME; ++j)
        isprime[i*j] = 0;
  for(int i = 2; i < MAX_PRIME;++i)
    if(isprime[i]) prime.push_back(i);   
}
void solve(long long x) {
  long long prije = x;
  factor.resize(prime.size());
  for(int ok = 1; ok;) {
    ok = 0;
    for(int i = 0; i < prime.size(); ++i)
      if(x % prime[i] == 0) {
        x /= prime[i];
        ++factor[i];
        ok = 1;
        break;
      }
  }
  long long vani = 1, unutra = 1;
  for(int i = 0; i < factor.size(); ++i) {
    if(factor[i] > 1) vani *= po(prime[i], factor[i]/2);
    if(factor[i]%2) unutra *= prime[i];
  }
  double pod = (double)unutra/pow10(after);
  if(vani > 1) {
    if(fabs(pod - 1) > 1e-9) printf("%lld*sqrt(%g)", vani, pod);
    else printf("%lld", vani);
  }
  else if(after) printf("sqrt(%g)", pod);
  else printf("Error!");
}
long long input() {
  int ret = 0;
  string s;
  cin >> s;
  size_t ind = s.find('.');
  if(ind != string::npos) {
    string post(s.begin()+ind+1, s.end());
    ret = atoi( post.c_str() );
    string pred(s.begin(), s.begin()+ind);
    after = post.size();
    ret += (long long) atoi( pred.c_str() ) * pow10(after);
  }
  else ret = atoi( s.c_str() );
  return ret;
}
int main() {
  precompute();
  solve(input());
  return 0;
}
