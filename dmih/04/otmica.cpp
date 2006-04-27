#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#define IN "3in.txt"
#define MAX 100
#define MAX_N 10000
using namespace std;
FILE *fajl; int maxi = -1, n_sol = 0;
set<pair<int, int> > bioje;
int neb[MAX][MAX], polje[MAX][MAX], le[MAX_N], ri[MAX_N];
int R,S, N;
int lx[4] = {1,0,0,1}, ly[4] = {0,0,1,1}, rx[4] = {1,1,0,0}, ry[4] = {1,0,0,1};
int susj[4][2] = {0,1,-1,0,0,-1,1,0};
queue<pair<int, int> > q[2];
bool curr = 0, next = 1;
void print();
void init();
pair<int, int> pol(int yy, int xx, int sm) {
    if(sm == 0) xx--;
    else if(sm == 2) yy--;
    else if(sm == 3) {xx--, yy--;}
    return make_pair<int, int> (yy, xx);
}
bool probaj(int yy, int xx, int sm, int k) {
    if(sm == 0) yy++;
    else if(sm == 1) xx++;
    else if(sm == 2) yy--;
    else if(sm == 3) xx--;
    if(yy >= 0 && yy < R && xx >= 0 && xx < S)
      if(ri[k] == neb[yy][xx]) return true;
    return false;
} 
void dodaj(pair<int, int> par) {
    if(par.first >= 0 && par.first < R && par.second >= 0 && par.second < S &&
       bioje.find(par) == bioje.end())  {
           bioje.insert(par);
           polje[par.first][par.second] = 0;
           q[curr].push(par);   
     }    
}           
void bfs() {
    pair<int, int> par;
    for(int i = 0; i < N; i++) {
        for(; !q[curr].empty(); q[curr].pop()) {
            pair<int, int> t = q[curr].front();
            //print();
            //printf("[%d %d]", t.first+1, t.second+1);
            maxi >?= i+1;
            /*if(polje[t.first][t.second] == N) {
                printf("%d %d\n", t.first+1, t.second+1);
                /*printf("\nKraj!");
                scanf("\n");
                exit(0);
                n_sol++;
            }*/
            for(int smjer = 0; smjer < 4; smjer++)    
              if(t.second+lx[smjer] < S && t.second+lx[smjer] >= 0 && 
                 t.first+rx[smjer] < S && t.second+rx[smjer] >= 0 &&
                 t.second+ly[smjer] < R && t.second+ly[smjer] >= 0 && 
                 t.first+ry[smjer] < R && t.second+ry[smjer] >= 0)
                if(neb[t.first+ly[smjer]][t.second+lx[smjer]] == le[ i ]
                  && neb[t.first+ry[smjer]][t.second+rx[smjer]] == ri[ i ])
                   if(t.first+susj[smjer][0] < R-1 && t.first+susj[smjer][0] >= 0 &&
                      t.second+susj[smjer][1] < S-1 && t.second+susj[smjer][1] >= 0) {
                      if(polje[t.first+susj[smjer][0]][t.second+susj[smjer][1]] != i+1) {
                        polje[t.first+susj[smjer][0]][t.second+susj[smjer][1]]=i+1;  
                        q[next].push(make_pair<int, int>(t.first+susj[smjer][0], t.second+susj[smjer][1]));
                      }    
                   }    
                       
                
        }
        curr ^= 1; next ^= 1;
    }       
} 
void init() {
    for(int i = 0; i < MAX; i++)
      for(int j = 0; j < MAX; j++) polje[i][j] = -1;
}
void print() {
     for(int i = 0; i < R-1; i++) {
      for(int j = 0; j < S-1; j++) printf("%3d", polje[i][j]);
      printf("\n");
     }  
     printf("---\n");  
}           
int main() {
    fajl = fopen("in3.txt", "r");
    init();
    fscanf(fajl, "%d %d", &R, &S);
    for(int i = 0; i < R; i++)
      for(int j = 0; j < S; j++) fscanf(fajl,"%d", &neb[i][j]);
    fscanf(fajl,"%d", &N);
    for(int i = 0; i < N; i++) fscanf(fajl,"%d", &le[i]);
    for(int i = 0; i < N; i++) fscanf(fajl,"%d", &ri[i]);
    for(int yy = 0; yy < R; yy++)
      for(int xx = 0; xx < S; xx++)
        if(neb[yy][xx] == le[0])
          for(int smjer = 0; smjer < 4; smjer++) 
            if(probaj(yy, xx, smjer, 0))                     
              dodaj(pol(yy, xx, smjer));
    bfs();                 
    printf("\n%d %d (max = %d)(n_sol = %d)!", q[curr].front().first+1, q[curr].front().second+1, 
      maxi, n_sol); 
    if(!q[curr].empty()) for(q[curr].pop(); !q[curr].empty(); q[curr].pop()) 
      printf("\n%d %d", q[curr].front().first+1, q[curr].front().second+1);
    printf("\n");
    print();
    scanf("\n");
    return 0;
} 
/*
10 10
07 06 03 07 04 05 08 10 09 03
02 06 09 02 09 06 04 07 02 07
05 06 10 07 03 03 01 01 02 05
07 08 03 09 07 06 05 04 05 05
06 07 01 06 08 01 03 03 09 07
02 03 04 01 02 06 05 04 06 06
08 05 04 10 05 10 05 10 05 02
04 10 10 06 07 09 06 01 01 04
09 04 09 03 04 02 08 01 05 06
06 04 02 01 04 06 02 10 07 06
25
7 7 4 4 1 2 9 9 6 7 7 7 5 10 9 7 5 5 2 1 6 1 5 6 5
6 4 7 3 3 9 2 3 3 4 9 5 7 9 10 5 7 10 6 6 1 6 6 5 6
*/
   
