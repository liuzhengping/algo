#include <fstream>
#include <iostream>
#include <cstdio>
#include <vector>
#include <conio.h>
#include <algorithm>
using namespace std;
int polje[101][101], niz[101][2];
int n, start, end;
int main() {
    ifstream in("graf3.txt", ios::in);
    in >> n >> start >> end;
    for(int i = 1; i <= n; i++) {
        int f, a, b;
        in >> f;
        if(f) {in >> a >> b;
        polje[i][0] = a;  polje[i][a] = b;
        printf("(%d,%d)", a, b);}
        for(int j = 2; j <= f; j++) {
            
            in >> a >> b;
            printf("(%d,%d)", a, b);
            polje[i][a] = b;
        }  
        printf("\n");  
    }
    /*//Floyd
    for(int j = 1; j <= n; j++) 
      for(int x = 1; x <= n; x++) 
          if(polje[x][j])
            for(int y = 0; y <= n; y++)
              if(polje[j][y])
                if(!polje[x][y] || polje[x][j]+polje[j][y]<polje[x][y])
                    polje[x][y]=polje[x][j]+polje[j][y];
     */
     //DIJKSTRA
    for(int i = 1; i <= n; i++) 
        niz[i][0] = polje[start][i];
    niz[100][0] = 32767;
    for(;;) {
        //smallest
        int min = 100;
        for(int i = 1; i <= n; i++) 
          if(niz[i][0] && !niz[i][1] && (niz[i][0] < niz[min][0])) min = i;
        if(min == 100) break; //ako su svi nodeovi prosli izadji
        for(int i = 1; i <= n; i++) 
            if(polje[min][i])
              if(!niz[i][0] || niz[min][0]+polje[min][i]<niz[i][0]) 
                niz[i][0] = niz[min][0]+polje[min][i]; 
        niz[min][1] = 1;
    }
    for(int j = 1; j <= n; j++) 
      for(int x = 1; x <= n; x++) 
          if(polje[x][j])
            for(int y = 0; y <= n; y++)
              if(polje[j][y])
                if(!polje[x][y] || polje[x][j]+polje[j][y]<polje[x][y])
                    polje[x][y]=polje[x][j]+polje[j][y];       
    for(int i = 1; i <= n; i++)  printf("%2d", niz[i][0]);
    printf("\n\n\n");
    for(int i = 1; i <= n; i++)  printf("%2d", polje[start][i]);
    /*for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++)
          printf("%2d", polje[i][j]);
        printf("\n");
    }   */    
    int tmp; scanf("%d", &tmp);
    return 0;
}    
        
    
