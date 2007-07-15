#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#define MAX 5003
using namespace std;
int n, dp[MAX];
struct blok {
  int t, n;
};
vector<blok> b;
struct comp {
  bool operator()(const blok& a, const blok& b) {
    return a.n-b.t > b.n-a.t;
  }  
} mojsort;  
void solve() {
  sort(b.begin(), b.end(), mojsort);
  memset(dp, -1, sizeof(dp)); //na pocetku su sve nosivosti -1 tj. ne postoji kula visine >
  for(int i = 0; i < n; ++i) {
    for(int j = i; j >= 0; --j) {
      if(!j) dp[1] >?= b[i].n;  //ako stavljas na prazno onda bolje uzet da bude najveca nosivost
      else dp[j+1] >?= min(dp[j] - b[i].t, b[i].n);  //inace stavi taj blok ako bi time povecao nosivost kule od j+1 blokova
    } 
  }
  int sol = 0;
  for(int i = 1; i <= n && dp[i] >= 0; ++i) sol = i; //nadji najvisu kulu koja ima nosivost >= 0
  printf("%d", sol); 
}  
void input() {
  scanf("%d", &n);
  b.resize(n);
  for(int i = 0; i < n; ++i) scanf("%d%d", &b[i].t, &b[i].n);
}  
int main() {
  input();
  solve();
  return 0;
}  
