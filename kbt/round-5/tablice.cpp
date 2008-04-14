#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 60
using namespace std;
int n;
vector<pair<string, int> > s[26];
vector<string> sol;
vector<vector<int> > edge;
int bio[MAX], dad[MAX], link[MAX], ne[MAX];
int dfs(int x) {
  if(bio[x]) return 0;
  bio[x] = 1;
  for(vector<int>::iterator it = edge[x].begin(); it != edge[x].end(); ++it)
    if(dad[*it] != x && ( dad[*it] == -1 || dfs(dad[*it]) ) ) {
      dad[*it] = x;
      link[x] = *it;
      return 1;
    }  
  return 0;
} 
int matching(int x) {
  if(s[x].empty()) return 1;
  if(s[x].size() > 26) return 0;
  edge.clear();
  edge.resize(MAX);
  memset(dad, -1, sizeof dad);
  memset(link, -1, sizeof link);
  for(int i = 0; i < s[x].size(); ++i) {
    for(int j = 1; j < s[x][i].first.size(); ++j)
      if(s[x][i].first[j] != 'A'+x && !ne[s[x][i].first[j]-'A'])
        edge[i].push_back(26+s[x][i].first[j]-'A');
  }  
  int flow = 0;
  for(int i = 0; i < MAX; ++i) {
    memset(bio, 0, sizeof bio);
    flow += dfs(i);
  }  
  for(int i = 0; i < s[x].size(); ++i) {
    string tab;
    tab.push_back( s[x][i].first[0] );
    tab.push_back( link[i]+'A'-26 );
    sol[ s[x][i].second ] = tab;
  }  
  return flow == s[x].size();
}  
int solve() {
  for(int i = 0; i < 26; ++i)
    if(!matching(i)) return 0;
  return 1;  
}  
void input() {
  scanf("%d", &n);
  sol.resize(n);
  for(int i = 0; i < n; ++i) {
    static char buff[150];
    scanf("%s", &buff);
    s[buff[0]-'A'].push_back( make_pair(buff, i) );
  }  
}  
void output() {
  for(int i = 0; i < n; ++i)
    printf("%s\n", sol[i].c_str()); 
}  
int main() {
  input();
  if( solve() ) output();
  else printf("NEMOGUCE\n");
  scanf("\n");
  return 0;
}


