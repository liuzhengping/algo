#include <cstdio>
#include <iostream>
#include <stack>
#define MAX 500005
using namespace std;
long long dp[MAX];
int a[MAX], pred[MAX], pred2[MAX], n;
long long sol;
stack<pair<int, int> > s, s2;
void solve() {
  if(n == 1) return ;
  for(int i = 0; i < n; ++i) pred[i] = pred2[i] = -1;
  s.push(make_pair(a[n-1], n-1));
  s2.push(make_pair(a[n-1], n-1));
  for(int i = n-2; i >= 0; --i) {
    if(a[i] >= a[i+1]) {
      for(pair<int, int> x;!s.empty(); s.pop()) {
        x = s.top();
        if(x.first > a[i]) break;
        pred[x.second] = i;
      }
      for(pair<int, int> x;!s2.empty(); s2.pop()) {
        x = s2.top();
        if(x.first >= a[i]) break;
        pred2[x.second] = i;
      }  
    }
    s.push(make_pair(a[i], i));
    s2.push(make_pair(a[i], i));
  }
  int last;
  for(int i = 1; i < n; ++i) {
    if(pred[i] == -1) last = 0;
    else last = dp[ pred[i] ] + 1;
    dp[i] = last;
  }       
  for(int i = 1; i < n; ++i) {
    long long ne;
    if(a[i] >= a[i-1]) {
      if(pred2[i] == -1) ne = 0;
      else ne = dp[ pred2[i] ];   
      sol += dp[i-1] - ne;
    }
    ++sol; 
  }    
}  
void input() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
}  
void output() {cout << sol;}
int main() {
  input(); 
  solve();
  output();
  //scanf("\n");
  return 0;
}
/*
7
2
4
1
2
2
5
1
*/    
