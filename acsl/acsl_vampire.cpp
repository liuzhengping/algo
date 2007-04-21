#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iterator>
using namespace std;
int n;
vector<char> v;
vector<pair<int, int> > sol;
void probaj(int a, int b) {
  if(a < b) swap(a, b);
  if(a % 100 && b % 100) {
    if(a*b == n) sol.push_back(make_pair(a, b));
  }  
}  
void solve() {
  sort(v.begin(), v.end());
  int mid = v.size()/2;
  do {
    string s1, s2;
    for(int i = 0; i < mid; ++i) s1.push_back(v[i]);
    for(int i = 0; i < mid; ++i) s2.push_back(v[i+mid]);
    probaj(atoi(s1.c_str()), atoi(s2.c_str()));
  } while(next_permutation(v.begin(), v.end()));  
  sort(sol.begin(), sol.end());
  sol.erase( unique(sol.begin(), sol.end()), sol.end());
  for(vector<pair<int, int> >::iterator i = sol.begin(); i != sol.end(); ++i) 
    printf("%d %d, ", i->first, i->second);
}  
void input() {
  char s[20];
  scanf("%s", &s);
  n = atoi(s);
  for(int i = 0; i < strlen(s); ++i) 
    v.push_back(s[i]);
   //copy(v.begin(), v.end(), ostream_iterator<char>(cout, ""));  
}  
int main() {
  input();
  solve();
  scanf("\n");
  return 0;
}  
