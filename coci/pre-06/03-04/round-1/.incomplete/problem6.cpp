#include <cstdio>
#include <queue>
#include <iostream.h>
#include <fstream>
#define MAX 100
using namespace std;
int oblik[MAX][MAX], polje[MAX][MAX];
int start[2], end[2]; int susj[4][2];
void init() {
    susj[0][0] = 0; susj[0][1] = 1;
    susj[1][0] = 1; susj[1][1] = 0;
    susj[2][0] = 0; susj[2][1] = -1;
    susj[3][0] = -1; susj[3][1] = 0;
}    
int main() {
    int m, n, f, g;
    int x, y;
    bool nadjeno = 0;
    ifstream in("zad6in.txt", ios::in);
    init();
    in >> m >> n;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            char c;
            ponovi:
            c = in.get();
            //printf("%c", c);
            if(c == '\n') goto ponovi;
            if(c == '#') oblik[i][j] = 1;
            else oblik[i][j] = 0;
        }
        in.get();
    }
    in >> f >> g; in.get();
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < g; j++) {
            char c;
            ponovi2:
            c = in.get();
            //printf("%c", c);
            if(c == '%') polje[i][j] = -1;
            else if(c == '1') {polje[i][j] = -2; start[0] = i; start[1] = j;}
            else if(c == '2') {polje[i][j] = -3; end[0] = i; end[2] = j;}
            //else goto ponovi2;
        }
        in.get();
    }
    queue<int> Q[2];
    Q[0].push(start[0]);
    Q[1].push(start[1]);
       for(int i = 0; i < m; i++) {
          for(int j = 0; j < n; j++)
            printf("%2d", oblik[i][j]);
          printf("\n");
        } 
        for(int i = 0; i < f; i++) {
          for(int j = 0; j < g; j++)
            printf("%2d", polje[i][j]);
          printf("\n");
        }   
    polje[start[0]][start[1]] = 0;   
    while(!Q[0].empty() && !nadjeno) {
        x = Q[0].front();
        y = Q[1].front();
         //printf("\n");       
        Q[0].pop();
        Q[1].pop();
        //provjera
        for(int smjer = 0; smjer < 4; smjer++) {
          if(polje[x+susj[smjer][0]][y+susj[smjer][1]] < 1 
             && susj[smjer][0]+x < f && susj[smjer][1]+y < g) {
              for(int i = 0; i < m; i++) {
                  for(int j = 0; j < n; j++) {
                      /*if(susj[smjer][0]+x+i >= f || susj[smjer][1]+y+j >= g) 
                        goto ne;*/
                      if(oblik[i][j] && polje[susj[smjer][0]+x+i][susj[smjer][1]+y+j] == -1) 
                        goto ne;
                  }
              }
              if(polje[x+susj[smjer][0]][y+susj[smjer][1]] == -3) {
                printf("Rez je %d\n", polje[x][y]+1);
                nadjeno = 1;
              }
              if(susj[smjer][0]+x >= 0 && susj[smjer][1]+y >= 0) {    
                Q[0].push(susj[smjer][0]+x);
                Q[1].push(susj[smjer][1]+y);
             }    
             // printf("(%d %d)", x+susj[smjer][0],y+susj[smjer][1]); 
              polje[x+susj[smjer][0]][y+susj[smjer][1]] = polje[x][y]+1;
              ne:
              continue;
          }        
            
        }
     
                     
        
    } 
    printf("\n");
    for(int i = 0; i < f; i++) {
      for(int j = 0; j < g; j++) printf("%2d", polje[i][j]);
      printf("\n");
    }       
    scanf("%d", &x);            
                 
    return 0;
}    
