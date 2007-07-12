#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int n;
string s[4];   
vector<pair<int, int> > v;
struct cmp {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
    return (a.first-1)*(a.second-1) > (b.first-1)*(b.second-1);
  }  
};
int solve() {//slozenost 24*N^6 :) ali samo teoretski
  int n2 = n-2;
  for(int a = 2; a < n2; ++a)
    for(int b = 2; b < n2; ++b)
      v.push_back(make_pair(a, b));
  sort(v.begin(), v.end(), cmp()); //sortiranje po najvecem pravokutniku
  for(vector<pair<int, int> >::iterator it = v.begin(); it != v.end(); ++it) {
    const int& a = it->first;
    const int& b = it->second;
    int perm[] = {0,1,2,3}; //isprobavanje svih permutacija tih 4 stringa
    do {
      for(int p1 = 1; p1+a <= n2; ++p1)
        for(int r1 = 1; r1+b <= n2; ++r1) {
          if(s[perm[0]][p1] != s[perm[2]][r1]) continue;
          for(int p2 = 1; p2+a <= n2; ++p2) {
            if(s[perm[1]][p2] != s[perm[2]][r1+b]) continue;
            for(int r2 = 1; r2+b <= n2; ++r2)
              if(s[perm[0]][p1+a] == s[perm[3]][r2] &&
                 s[perm[1]][p2+a] == s[perm[3]][r2+b])
                   return (a-1)*(b-1);
          }  
        }          
    } while(next_permutation(perm, perm+4));
  }    
  return 0;
}    
int main() {
  scanf("%d", &n);
  for(int i = 0; i < 4; ++i) cin >> s[i];
  printf("%d", solve());
  return 0;
}

