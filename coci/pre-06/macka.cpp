#include <cstdio>
#include <vector.h>
#include <algorithm>
#include <iostream>
#include <list.h>
#include <queue.h>

vector <list<int> >v;
int N, A, B;
int main() {
    int inf = 32768;
 
    scanf("%d %d %d", &N, &A, &B); A--; B--;
    v.resize(N);
    for(int i = 0; i < N; i++) {
        int k, l; scanf("%d", &k);
        for(int j = 0; j < k; j++) {
          scanf("%d", &l); --l; v[i].push_back(l);
        }
    }
    vector<int> distA(N, inf), distB(N, inf); distA[A] = 0; distB[B] = 0;
    //macka
    queue<int> Q;
    for(Q.push(A); !Q.empty(); Q.pop()) {
        int x = Q.front();
        for(list<int>::iterator iter = v[x].begin(); iter != v[x].end(); iter++) {
          if(distA[*iter] == inf) {
            distA[*iter] = distA[x] + 1;
            Q.push(*iter); 
          }
        }
    }
    int sol = -1;
    for(Q.push(B); !Q.empty(); Q.pop()) {
       int x = Q.front();
       sol >?= distA[x];
       for(list<int>::iterator iter = v[x].begin(); iter != v[x].end(); iter++) {
           if(distB[*iter] == inf) {
               distB[*iter] = distB[x] + 1;
               if(distB[*iter] < distA[*iter]) Q.push(*iter);
           }
       }
    }

    printf("\n%d", sol);                                
    int tmp; scanf("%d", &tmp);
    return 0;
}    
