#include <cstdio>
#include <vector>
#include <iostream>
#define MAX 60005
using namespace std;
int n, from, a[MAX], nn, np;
int prime[2*MAX];
int sred[2];
vector<int> sol;
void input() {
  scanf("%d%d", &from, &n);
  n -= from-1;
  for(int i = 0; i < n; ++i) a[i] = from+i;
}
void solve() {
  int to = 2*(from+n);
  for(int i = 0; i < to; ++i) prime[i] = 1;
  for(int i = 2; i*i < to; ++i)
    if(prime[i])
      for(int j = i; j*i < to; ++j)
       prime[i*j] = 0;
  nn = np = n/2;
  if(n&1) {
    if(from&1) ++nn;
    else ++np;
  }
  sred[0] = sred[1] = 0;
  //pogledaj koji trebaju biti u sredini
  for(int i = from; i < from+n; ++i) 
    for(int j = i+1; j < from+n; j+=2) 
      if(!prime[i+j]) {
        sred[i&1] = i;
        sred[j&1] = j;
        break;
      }
  //napravi niz
  sol.reserve(n);    
  for(int i = from+(from&1); i < from+n; i+=2)
    if(sred[0] != i && sred[1] != i) sol.push_back(i);
  for(int i = 0; i < 2 && sred[i]; ++i) sol.push_back(sred[i]);
  for(int i = from+!(from&1); i < from+n; i+=2)
    if(sred[0] != i && sred[1] != i) sol.push_back(i);   
}
void output(int ok) { 
  if(!ok) {printf("0\n"); return ; }
  for(int i = 0; i < sol.size(); ++i) printf("%d\n", sol[i]);
}
int provjera() {
  for(int i = 1; i < sol.size(); ++i) if(prime[sol[i]+sol[i-1]]) return 0;
  return 1;
}      
int main() {
  int t;
  input();
  solve();
  output(provjera());
  return 0;
}


