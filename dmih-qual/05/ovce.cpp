#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <queue.h>
#include <fstream.h>
using namespace std;
int polje[250][250];
struct koord {
    int x, y;
    char c;
    int da;
} k[100];
struct broj {
    int o, v;
} no[100];                  
int main(void) {
  char c; bool found; const bool da = true;
  int x, y, m, n, b = 0, br = -1;
  int susj1[4] = {0, -1, 0, 1};
  int susj2[4] = {-1, 0, 1, 0};
  int vuk = 0, ovca = 0; 
  ifstream in ("i.txt", ios::in);
  queue<int> Q[2];
  for(int i = 0; i < 250; i++) {
        for(int j = 0; j < 250; j++) {
          polje[i][j] = 9;
        }
  }        
  in >> m >> n;
  for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
          ponovi:
          c = in.get(); 
          if(c == '.') polje[i][j] = 1;
          else if(c == '#') polje[i][j] = 9;
          else if(c == 'o' || c == 'v') {
              if(c == 'o') polje[i][j] = 2;
              else if(c == 'v') polje[i][j] = 3;  
              k[b].x = j; k[b].y = i; k[b].c = c;
              ++b;
          }
          else goto ponovi;
      }
  }
  for(int k1 = 0; k1 < b; k1++) cout << "{" << k[k1].x << k[k1].y;
  while(da) {
    found = false;  
    for(int t = 0; t < b; t++) {
        if(k[t].da != 1) {
            Q[0].push(k[t].x);
            Q[1].push(k[t].y);
            if(k[t].c == 'o')
              no[++br].o++;
            else if(k[t].c == 'v')
              no[++br].v++;
            k[t].da = 1;  
            polje[k[t].y][k[t].x] = 9;
            found = true;
            break;
        }
    }        
    if(!found)
      break;        
    while(!Q[0].empty() && !Q[1].empty()) {
        x = Q[0].front();
        y = Q[1].front();
        Q[0].pop(); Q[1].pop();
        for(int i = 0; i < 4; i++) {
            if(polje[y-susj1[i]][x-susj2[i]] != 9) {
                if(polje[y-susj1[i]][x-susj2[i]] == 2 ||
                   polje[y-susj1[i]][x-susj2[i]] == 3) {
                   if(polje[y-susj1[i]][x-susj2[i]] == 2)
                     no[br].o++;
                   else if(polje[y-susj1[i]][x-susj2[i]] == 3)
                     no[br].v++;
                   for(int l = 0; l < b-1; l++) {
                       if(k[l].x == x-susj2[i] && k[l].y == y-susj1[i])
                         k[l].da = 1;
                   }
                }
                Q[0].push(x-susj2[i]);
                Q[1].push(y-susj1[i]);
                polje[y-susj1[i]][x-susj2[i]] = 9;
            }
        }
    }
  } 
  for(int f = 0; f < br; f++) {
      if(no[f].v >= no[f].o)
        vuk+=no[f].v;
      else
        ovca+=no[f].o;
  }
  cout << endl << ovca << " " << vuk;        
  getch();
  return 0;
}                          
                    
                        
