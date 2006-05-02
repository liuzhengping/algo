#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#define MAX 501
using namespace std;
vector<string> str(MAX);
set<pair<int, int> > bio;
string sol("nemarjesenja");
int main() {
    int n;
    int maxl = 0; int poc = 2, kraj = 500; int br = 0;
    set<pair<int, int> >::iterator iter;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) cin >> str[i];
    for(int poc = 0; poc < str[0].size(); poc++)
      for(int kraj = poc+1; kraj < str[0].size()+1; kraj++) {
          if((iter = bio.find(make_pair<int, int>(poc, kraj))) != bio.end()) {
              kraj = (*iter).second; continue;
          } 
          //printf("(%d %d)\n", poc, kraj);   
          string uz(str[0].begin()+poc, str[0].begin()+kraj);
          int ind;
          for(int i = 1; i < n; i++) {
              ind = str[i].find(uz);
              if(ind < 0) break;
          }
          if(ind >= 0 && kraj-poc > maxl) {
                  maxl = kraj-poc;
                  sol = uz; //cout << uz << endl;
                  for(int tpoc = poc+1; tpoc <= kraj; tpoc++)
                    for(int tkraj = tpoc; tkraj <= kraj; tkraj++)
                        bio.insert(make_pair<int, int>(tpoc, tkraj));
          }        
      }  
    cout << sol; 
    scanf("\n");
    return 0;
}    
