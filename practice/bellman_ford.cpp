#include <cstdio>
#include <cmath>
#include <fstream.h>
#include <iostream.h>
#define INF ( (int) pow(2, sizeof(int)*8-2)-1)
#define MAX 101
int p[MAX][MAX], polje[MAX][MAX];
void init() {

}
void path(int i, int j) {
    if(i != j)
        path(i, p[i][j]);
    printf("%2d", j);

}
int main() {
    //init();
    int n, m; int l, k, st; bool da;
    ifstream in ("bellman_ford.txt", ios::in);
    in >> m >> n >> st;
    for(int i = 0; i < m; i++)
      for(int j = 0; j < m; j++) {
        if(i != j) polje[i][j] = INF;
        else polje[i][j] = 0;
        p[i][j] = 0;
    }
    for (int i = 0; i < n; i++) {
      int dist;
      in >> l >> k >> dist;
      --l;
      --k;
      polje[l][k] = dist;
    }
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < m; j++)
          printf("%10d", polje[i][j]);
      printf("\n");
    }
    for(int i = 0; i < m; i++) {
        da = 0;
        for(int j = 0; j < m; j++) {
            if(polje[st][i] > polje[st][j] + polje[j][i]) {
              polje[st][i] = polje[st][j] + polje[j][i];
              p[st][i] = j;
              da = 1;
            }
        }
    }
    if(da) printf("Nadjen negativni krug\n");


    printf("\n\n\n");
    for(int j = 0; j < m; j++) printf("%2d", polje[st][j]);
    printf("\nPut: ");

    path(st, 1);
    int tmp; scanf("%d", &tmp);
    return 0;
}
