#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;
typedef pair<int, int> par;
struct ni {
    int a, b ,c; } niz[2000];
using namespace std;
int polje[201][201];
int main() {
    list<par> sol;
    int n, k, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n ;j++)
        if(i < j) sol.push_back( make_pair< int, int > (i, j) );
        
    for(int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        polje[--a][--b] = c;
        polje[b][a] = c;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) 
      scanf("%d %d %d", &niz[i].a, &niz[i].b, &niz[i].c);
    for(int j = 0; j < n; j++)   
      for(int x = 0; x < n; x++)  
        if(polje[x][j])
          for(int y = 0; y < n; y++)
            if(polje[j][y])
              if(!polje[x][y] || polje[x][y] > polje[x][j]+polje[j][y])
                polje[x][y] = polje[x][j]+polje[j][y];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n ; j++) 
          printf("%d ", polje[i][j]);
        printf("\n");
    }    
    for(int i = 0; i < k; i++)
      for(list<par>::iterator it = sol.begin(); it != sol.end(); it++) {
          int d = polje[niz[i].a-1][niz[i].b-1];
          if(polje[niz[i].a-1][(*it).first] && polje[(*it).second][niz[i].b-1])
            d <?= (polje[niz[i].a-1][(*it).first]+polje[(*it).second][niz[i].b-1]);
          if(polje[niz[i].a-1][(*it).second] && polje[(*it).first][niz[i].b-1])
            d <?= (polje[niz[i].a-1][(*it).second]+polje[(*it).first][niz[i].b-1]);
          if(d != niz[i].c) sol.erase(it);
      }    
        
    /*for(int i = 0; i < k; i++)
      if(polje[niz[i].a-1][niz[i].b-1] > niz[i].c)
         polje[niz[i].a-1][niz[i].b-1] = niz[i].c;
        //vector.push_back(make_pair(
    for(int j = 0; j < n; j++)   
      for(int x = 0; x < n; x++)  
        if(polje[x][j])
          for(int y = 0; y < n; y++)
            if(polje[j][y])
              if(!polje[x][y] || polje[x][y] > polje[x][j]+polje[j][y])
                polje[x][y] = polje[x][j]+polje[j][y];
    printf("\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n ; j++) 
          printf("%d ", polje[i][j]);
        printf("\n");
    } */
    list<par>::iterator iter = sol.begin();
    printf("%d %d", (*iter).first, (*iter).second);   
    scanf("\n");
    return 0;
}    
