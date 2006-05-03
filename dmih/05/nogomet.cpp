#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
int n, k; //0 bod, 1 golraz, 2 gol, 3 dob.gol, 4 br.pob., 5 rbr
struct utakmice {
    int a, b, c, d;
} ut[1001];
struct timovi {
    int bod[5];
    int rbr;
} team[101];    
void qs(int l, int r, int ind) {
    if(r > l) {
        int i, v, j;
        j = r; i = l-1; v = team[r].bod[ind];
        for(;;) {
            while(team[++i].bod[ind] > v);
            while(team[--j].bod[ind] < v);
            if(i >= j) break;
            swap(team[i], team[j]);
        }
        swap(team[i], team[r]);
        qs(l, i-1, ind);
        qs(i+1, r, ind);    
    }    
}
void qsuz(int l, int r, int ind) {
    if(r > l) {
        int i, v, j;
        j = r; i = l-1; v = team[r].bod[ind];
        for(;;) {
            while(team[++i].bod[ind] < v);
            while(team[--j].bod[ind] > v);
            if(i >= j) break;
            swap(team[i], team[j]);
        }
        swap(team[i], team[r]);
        qs(l, i-1, ind);
        qs(i+1, r, ind);    
    }    
}
void init() {
    for(int i = 0; i < 100; i++) team[i].rbr = team[i].bod[5] = i;
}
void zbroji1() {
    for(int i = 0; i < k; i++) {
      if(ut[i].c > ut[i].d) {
          team[ut[i].a].bod[0]+=3;
          team[ut[i].a].bod[4]++;
      }    
      else if(ut[i].c < ut[i].d) {
          team[ut[i].b].bod[0]+=3;
          team[ut[i].b].bod[4]++;
      }    
      else if(ut[i].c == ut[i].d) {
          team[ut[i].a].bod[0]++; team[ut[i].b].bod[0]++;
      } 
      team[ut[i].a].bod[1]+=ut[i].c-ut[i].d;
      team[ut[i].b].bod[1]+=ut[i].d-ut[i].c;
      team[ut[i].a].bod[2]+=ut[i].c; team[ut[i].a].bod[3]+=ut[i].d;
      team[ut[i].b].bod[2]+=ut[i].d; team[ut[i].b].bod[3]+=ut[i].c;
    }       
}
int nadji(int poc, int kraj, int x) {
    for(int i = poc; i <= kraj; i++) 
      if(team[i].rbr == x) return 1;
    return 0;
}    
void preslozibod(int poc, int kraj) {
    for(int i = poc; i <= kraj; i++) 
      team[i].bod[0]=0;
    for(int i = 0; i < k; i++) {
     if(nadji(poc, kraj, ut[i].a) && nadji(poc, kraj, ut[i].b)) {
      if(ut[i].c > ut[i].d) {
          team[ut[i].a].bod[0]+=3;
          //team[ut[i].a].bod[4]++;
      }    
      else if(ut[i].c < ut[i].d) {
          team[ut[i].b].bod[0]+=3;
          //team[ut[i].b].bod[4]++;
      }    
      else if(ut[i].c == ut[i].d) {
          team[ut[i].a].bod[0]++; team[ut[i].b].bod[0]++;
      } 
     }
   }        
}       
void rek(int poc, int kraj, int ind) {
    bool isto = true;
    for(int i = poc; i < kraj; i++) 
      if(team[i].bod[ind] != team[i].bod[ind]) {
          isto = false; break; 
      }
    if(isto) { 
        rek(poc, kraj, ind+1); //sortira po 1-5
        return;
    }    
    if(ind !=3) qs(poc, kraj-1, ind);
    else qsuz(poc, kraj-1, ind);
    if(!ind) {
        //od kuda do kuda za bod[0]
        for(int i = poc; i < kraj; i++) {
            int j;
          for(j = poc; j <= kraj && team[i].bod[ind] == team[j].bod[ind]; j++) ;
          if(--j != poc) {  //ako postoji vise njih s istim bod[0]
             preslozibod(i, j);
             rek(i, j, ind);
          }    
          
        }    
    }
}                    
int main() {
    init();
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++)
     scanf("%d %d %d:%d", &ut[i].a, &ut[i].b, &ut[i].c, &ut[i].d);
    zbroji1();
    rek(1,n+1,0);
    for(int i = 1; i <= n; i++) 
        printf("%d: %d %d %d %d %d\n", team[i].rbr, team[i].bod[0], team[i].bod[1],
        team[i].bod[2], team[i].bod[3], team[i].bod[4]);
    scanf("\n");
    return 0;
}
/* 
5 4
2 3 5:2
3 4 7:3
5 3 1:2
4 5 2:2
*/
/*
1: 0 0 0 0 0
2: 3 3 5 2 1
3: 6 2 11 9 2
4: 1 -4 5 9 0
5: 1 -1 3 4 0*/
  
