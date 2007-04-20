#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX 1000002
using namespace std;
struct broj {
  char a; short b; 
  broj() {}
  inline broj(int x) {
    a = x/32000;
    b = x%32000;
  }  
};
bool operator<(const broj& a, const broj& b) {
  if(a.a < b.a) return 1;
  if(a.a > b.a) return 0;
  return a.b < b.b;
} 
bool operator==(const broj& a, const broj& b) {
  return a.a == b.a && a.b == b.b;
}
bool operator==(const pair<broj, broj>& a, const pair<broj, broj>& b) {
  return a.first == b.first && a.second == b.second;
}  
struct comp {
  bool operator()(const pair<broj, broj>& a, const pair<broj, broj>& b) {
    if(a.first < b.first) return 1;
    if(b.first < a.first) return 0;
    return a.second < b.second;
  }  
} mojsort;    
pair<broj, broj> a[MAX];
int main() {
  int n; char s[10];
  int x = 1000000, y = 1000000;
  scanf("%d", &n);
  a[0] = make_pair(broj(x), broj(y));
  for(int i = 1; i <= n; ++i) {
    scanf("%s", &s);
    if(s[2] == 'r') ++y;
    else if(s[2] == 'l') --y;
    else if(s[2] == 'v') --x;
    else if(s[2] == 's') ++x;
    else scanf("%*s%*s%*s");
    a[i] = make_pair(broj(x), broj(y));
  }
  sort(a, a+n+1, mojsort);
  int curr = 1, sol = 1;
  for(int i = 1; i <= n; ++i, sol >?= curr) {
    if(a[i-1] == a[i]) ++curr;
    else curr = 1;
  }
  printf("%d", sol);
  return 0;
} 
