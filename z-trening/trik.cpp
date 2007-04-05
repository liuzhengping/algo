#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n, k;
vector<pair<int, int> >  v;
void solve() {
  scanf("%d%d", &n, &k); --k;
  v.resize(n);
  for(int i = 0; i < n; ++i) {
    int broj, boja;
    char buff[5]; scanf("%s", &buff);
    if(strlen(buff) == 3) broj = 10;
    else if(buff[1] == 'J') broj = 11;
    else if(buff[1] == 'Q') broj = 12;
    else if(buff[1] == 'K') broj = 13;
    else if(buff[1] == 'A') broj = 14;
    else broj = buff[1] - '0';
    if(buff[0] == 'S') boja = 1;
    else if(buff[0] == 'L') boja = 2;
    else if(buff[0] == 'K') boja = 3;
    else boja = 4;
    v[i] = make_pair(boja, broj);
  }
  sort(v.begin(), v.end());
}
void ispis() {
  if(v[k].first == 1) printf("S");
  else if(v[k].first == 2) printf("L");
  else if(v[k].first == 3) printf("K");
  else if(v[k].first == 4) printf("D");
  if(v[k].second == 11) printf("J");
  else if(v[k].second == 12) printf("Q");
  else if(v[k].second == 13) printf("K");
  else if(v[k].second == 14) printf("A");
  else if(v[k].second == 10) printf("10");
  else printf("%c", v[k].second+'0');
}    
int main() {
  solve();
  ispis();
  return 0;
}  
