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
int rec(int d, int mult) {
  if(d >= pf.size()) return mult; 
  int sum = 0;
  for(int i = 0, r = 1; i <= pf[d].second; ++i, r *= pf[d].first)
    sum += rec(d+1, mult*r); 
  return sum;  
}  
void fact(const int x) {
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
