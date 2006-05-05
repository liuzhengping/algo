#include <cstdio>
#include <cstdlib>
#include <iostream>
#define MAX 10001
using namespace std;
int k[2][MAX];
int niz[100];
int N, K;
const long long int inf = 1000000001;
void init() {
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < MAX; j++)
        k[i][j] = - inf;
    for(int i = 0; i < MAX; i++) k[0][i] = 0;
}    
int main() {
    int curr = 1, prev = 0;
    scanf("%d %d", &N, &K);
    init();
    for(int i = 1; i <= N; i++) scanf("%d", &niz[i]);    
    for(int j = 1; j <= K; j++) {
      int x = (j % 2) ? 1 : -1;
      for(int i = j; i <= N; i++) 
          k[curr][i] = max(k[prev][i-1]+x*niz[i], k[curr][i-1]); 
      curr ^= 1; prev ^= 1;
    }
    printf("%lld", k[prev][N]);       
    scanf("\n");
    return 0;
}    
