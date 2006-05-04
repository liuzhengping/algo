#include <cstdio>
#include <vector.h>
#include <algorithm>
const int inf = 32768;
struct edge {
    int so; int de; int w;
};
vector<edge> E; 
int N, M, A, B;
vector<int> pred;
void rek(int x, int key) {
    if(pred[x] && pred[x] != key)
      rek(pred[x], key);
    printf("%d ", x+1);
}       
int main() {
    scanf("%d %d %d %d", &N, &M, &A, &B); A--; B--;
    E.resize(M);
    for(int i = 0; i < M; i++) {
        scanf("%d %d %d", &E[i].so, &E[i].de, &E[i].w);
        E[i].so--; E[i].de--;
    }
    vector<int> dist(N, inf);
    pred.resize(N);
    dist[A] = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(dist[E[j].de] > dist[E[j].so] + E[j].w) {
              dist[E[j].de] = dist[E[j].so] + E[j].w;
              pred[E[j].de] = E[j].so;
            }    
        }
    }
    for(int i = 0; i < N; i++) printf("%d ", dist[i]);
    printf("\n\n");
    printf("%d ", A+1); rek(B, A);  
    
    scanf("\n");
    return 0;
}  
/*
6 9 4 3
1 2 3
1 5 2
2 3 1
3 4 4
4 2 2
4 1 4
4 6 5
5 3 2
6 5 1
*/      
