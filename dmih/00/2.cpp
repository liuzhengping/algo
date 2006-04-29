#include <queue> 
#include <cstdio>
#include <vector>
using namespace std;
queue<int> donji, gornji;
vector<int> v;
inline void ubaci(int stanje) {v.push_back(stanje);}
void printaj() { 
      for(int i = 0; i < v.size(); i++) {
        if(v[i] == 1) printf("gurni na gornji\n");
        else if(v[i] == 2) printf("gurni na donji\n");
        else if(v[i] == 3) printf("gurni s gornjeg\n");
        else if(v[i] == 4) printf("gurni s donjeg\n");    
      }    
}    
int main() {
    int n, niz[1001];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &niz[i]);
    int tre = 1;
    for(int i = 0; i < n; i++) {
        if(niz[i] == tre) {
          if(gornji.empty()) {
              gornji.push(niz[i]); ubaci(1);
              gornji.pop(); ubaci(3);
              tre++;
              for(;!gornji.empty() && gornji.front() == tre; gornji.pop(), ubaci(3), tre++);
              for(;!donji.empty() && donji.front() == tre; donji.pop(), ubaci(4), tre++);
          }
          else if(donji.empty()) {
              gornji.push(niz[i]); ubaci(2);
              gornji.pop(); ubaci(4);
              tre++;
              for(;!donji.empty() && donji.front() == tre; donji.pop(), ubaci(4), tre++);
              for(;!gornji.empty() && gornji.front() == tre; gornji.pop(), ubaci(3), tre++);
          }
        }
        else if(!gornji.empty()) {
            gornji.push(niz[i]); ubaci(1);    
        } 
        else { donji.push(niz[i]); ubaci(2); }              
    }
    for(;!gornji.empty() && gornji.front() == tre; gornji.pop(), ubaci(3), tre++);   
    for(;!donji.empty() && donji.front() == tre; donji.pop(), ubaci(4), tre++);   
    if(gornji.empty() && donji.empty()) printaj();
    else printf("0");
    scanf("\n");
    return 0;
}    
