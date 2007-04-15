#include <cstdio>
#include <iostream>
#include <queue>
#define MAX 1505
using namespace std;
char a[MAX][MAX];
bool bioled[MAX][MAX], bio[MAX][MAX];
queue<pair<int, int> > led[2], lab[2];
int eny, enx, sty, stx, r, s, br;
inline bool ok(const pair<int, int>& p) {
  return p.first >= 0 && p.first < r && p.second >= 0 && p.second < s;
}
inline bool gotovo(const pair<int, int>& p) {
  return p.first == eny && p.second == enx;
}     
int solve() {
  static const int dxy[4][2] = {1,0,0,1,0,-1,-1,0};
  for(int i = 0; i < r; ++i)
    for(int j = 0; j < s; ++j) {
      if(a[i][j] == 'L') {
        if(!br) {++br; eny = i; enx = j;}
        else {
          sty = i; stx = j; 
          bio[i][j] = true;
          lab[0].push(make_pair(i, j));
        }
      }  
      if(a[i][j] != 'X') {
        bioled[i][j] = true;
        led[0].push(make_pair(i, j));
      }
    }  
  
  int dan = 0;
  for(int curr = 0, next = 1; ; curr ^= 1, next ^= 1, ++dan) {
    //otopi led
    for(;!led[curr].empty(); led[curr].pop()) {
      pair<int, int> p = led[curr].front();
      a[p.first][p.second] = '.';
      for(int i = 0; i < 4; ++i) {
        pair<int, int> np(p.first+dxy[i][0], p.second+dxy[i][1]);
        if(!ok(np)) continue;
        if(bioled[np.first][np.second]) continue;
        if(a[np.first][np.second] == 'X') led[next].push(np);
        else if(a[np.first][np.second] == '.') led[curr].push(np);
        bioled[np.first][np.second] = true;
      }  
    }
    //pokreni labuda
    for(;!lab[curr].empty(); lab[curr].pop()) {
      pair<int, int> p = lab[curr].front();
      if(gotovo(p)) return dan;
      for(int i = 0; i < 4; ++i) {
        pair<int, int> np(p.first+dxy[i][0], p.second+dxy[i][1]);
        if(!ok(np)) continue;
        if(bio[np.first][np.second]) continue;
        if(a[np.first][np.second] == '.') lab[curr].push(np); 
        else if(a[np.first][np.second] == 'X') lab[next].push(np); 
        bio[np.first][np.second] = true;
      }  
    }  
    //ispis();  
  }
  return -1;   
}  
void input() {
  scanf("%d%d", &r, &s);
  for(int i = 0; i < r; ++i) scanf("%s", &a[i]);
}  
int main() {
  input();
  printf("%d", solve());
  return 0;
}  

