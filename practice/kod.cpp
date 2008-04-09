#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
using namespace std;
int n;
map<string, string> next;
string dest;
void input() {
  static char buff[100];
  scanf("%d%s", &n, &buff);
  dest = buff;
  for(int i = 0; i < n; ++i) {
    scanf("%s", &buff);
    string s = buff;
    size_t ind1 = s.find(":");
    size_t ind2 = s.find("->");
    string ime1(s.begin()+ind1+1, s.begin()+ind2);
    string ime2(s.begin()+ind2+2, s.end());
    next[ime1] = ime2;
  }
}
void solve() {
  printf("%s", dest.c_str());
  string curr = next[dest];
  for(int i = 0; i < n; ++i, curr = next[curr])
    printf("->%s", curr.c_str());
}
int main() {
  input();
  solve();
  return 0;
} 