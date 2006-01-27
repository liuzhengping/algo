#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue.h>
using namespace std;
int polje[1000][1000];
int susjx[4] = {0,-1,1,0};
int susjy[4] = {-1,0,0,1};
int main() {
    int m, n, st_x, st_y, x, y; bool da = true;
    queue<int> qx, qy;
    scanf("%d %d", &m, &n);
    for(int i = 0; i < n; i++) {
        char str[1000]; scanf("%s", &str);
        for(int j = 0; j < m; j++) {
            char c = str[j];
            if(c == '#') polje[i][j] = -2;
            else polje[i][j] = -1;
        }
    }
    
    /*for(int i = 0; i < n && da; i++) {
        for(int j = 0; j < m; j++) {
            if(polje[i][j] == -1) {polje[i][j] = 0; st_y = i; st_x = j; 
            da = false; break;}
        }
    }*/
    st_x = 3; st_y = 1; polje[st_y][st_x] = 0;
    //BFS
    qx.push(st_x); qy.push(st_y);
    for(;!qx.empty(); qx.pop(),qy.pop()) {
        x = qx.front();
        y = qy.front();
        for(int i = 0; i < 4; i++) {
            if(susjx[i]+x>0 && susjx[i]+x<m && susjy[i]+y>0 && susjy[i]+y<n)
              if(polje[susjy[i]+y][susjx[i]+x] == -1) {
                polje[susjy[i]+y][susjx[i]+x] = polje[y][x]+1;
                qx.push(susjx[i]+x); qy.push(susjy[i]+y);
              } 
        }        
    }
    int sol = polje[y][x];
    int usp = sol;
    //gotov BFS - pocinje micanje puta
    qx.push(x); qy.push(y);
    polje[y][x] = -2;
    for(;!qx.empty(); qx.pop(),qy.pop()) {
        x = qx.front();
        y = qy.front();
        if(polje[y][x] == 0) break;
        for(int i = 0; i < 4; i++) {
            if(susjx[i]+x>0 && susjx[i]+x<m && susjy[i]+y>0 && susjy[i]+y<n)
              if(polje[susjy[i]+y][susjx[i]+x] == usp-1) {
                usp = polje[susjy[i]+y][susjx[i]+x];
                if(polje[susjy[i]+y][susjx[i]+x] != 0) 
                  polje[susjy[i]+y][susjx[i]+x] = -2;
                qx.push(susjx[i]+x); qy.push(susjy[i]+y);
                break;
              } 
        }        
    }
    //bfs 2
    qx.push(x); qy.push(y);
    for(;!qx.empty(); qx.pop(),qy.pop()) {
        x = qx.front();
        y = qy.front();
        for(int i = 0; i < 4; i++) {
            if(susjx[i]+x>0 && susjx[i]+x<m && susjy[i]+y>0 && susjy[i]+y<n)
              if(polje[susjy[i]+y][susjx[i]+x] == polje[y][x]+1) {
                qx.push(susjx[i]+x); qy.push(susjy[i]+y);
              } 
        }        
    }
    sol+=polje[y][x];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(polje[i][j] == -2) printf("#"); 
            else printf("%d",polje[i][j]);
        }
        printf("\n");
    } 
    printf("\n\n\n%d", sol);       
     scanf("%d", &m);           
    return 0;
}    
