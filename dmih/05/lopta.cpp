#include <cstdio>
#include <iostream>
using namespace std;
char polje[100][100], niz[100][2];
int sila[4][2] = {1,0,0,1,-1,0,0,-1};
int sm = 0;
void smjer(bool da) {
    if(da) {
       if(sm == 3) sm = 0;
       else sm++;
    }
    else {
        if(sm == 0) sm = 3;
        else sm--;
    }        
}     
int main() {
    int a, b; int x, y; int k;
    scanf("%d %d", &a, &k);
    b = a;
    for(int i = 0; i < a; i++) scanf("%s", &polje[i]);
    for(int i = 0; i < a; i++) 
      for(int j = 0; j < b; j++)
        if(polje[i][j] == 'L') {y = i; x = j;}
    printf("evo");
    scanf("%d", &k);
    for(int i = 0; i < k ; i++)
      scanf("%s", &niz[i]);
    int xx = x, yy = y;
    for(; polje[yy][xx] == '.' ;yy+=sila[sm][0], xx+=sila[sm][1]) {
       x = xx; y = yy;
    }    
    polje[y][x] = 'L';
    for(int i = 0; i < k; i++) {
        if(niz[i][0] == 'D') smjer(1);
        else if(niz[i][0] == 'L') smjer(0);
        polje[y][x] = '.';
        int xx = x, yy = y;
        for(; polje[yy][xx] == '.' ;yy+=sila[sm][0], xx+=sila[sm][1]) {
            x = xx; y = yy;
        }    
        polje[y][x] = 'L';
        for(int g = 0; g < a; g++) {
            for(int h = 0; h < b; h++) printf("%c ", polje[g][h]);
        printf("\n");
    }    
        printf("\n(%d)\n", sm);        
    }    
    for(int i = 0; i < a; i++) {
      for(int j = 0; j < b; j++) printf("%c ", polje[i][j]);
      printf("\n");    
    }    
    scanf("\n");
    return 0;
}  
/*
6 5
xxxxx
xL..x
xx..x
x.x.x
x...x
xxxxx
4
D
D
D
D
*/

