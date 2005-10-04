#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int Time[1000];
queue < int > v[1000];
queue < int > smet;
int main() {
    
    int m, t, x;
    int counter = 0;
    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        scanf("%d", &t); v[0].push(t);
    }
    
    //scanf("%d", &m);
    for(int i = 0; i < m; i++) {
      x = v[0].front();
      for(int dist = 0; dist <= x; Time[counter]++) {
           if(dist == x) {
             smet.push(x);  
             v[x].push(Time[counter++]+=5);
             break;
           }    
           if(v[dist+1].empty())
             dist++;
           else if( smet.size() == 1 && 
           
      }  
      v[0].pop();         
    }
     
    printf("%d", Time[0]);
    scanf("%d", &m);
    return 0;
}    
