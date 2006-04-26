#include <iostream>
#include <cstdio>
using namespace std;

#define MAX 700

long long rj[MAX+5][MAX+5];

int main (void) {
   int x, y;
   cin >> x >> y;
   
   /*for (int i=0; i<=x; i++)
     rj[0][i] = 1; 
     
   for (int i=1; i<=x; i++) {
     for (int j=1; j<=x; j++) {
        if (i-j>=0) rj[i][j] += rj[i-j][j-1];   
        rj[i][j] += rj[i][j-1];
     }   
  }   
    
  cout << rj[x][x-1] << endl;
  for(int j = 0; j <= 20; j++) {
    for(int i = 0; i <= 20; i++) printf("%3lld", rj[j][i]);
    printf("\n");
}    */
  for(int i = 0; i <= x; i++) rj[1][i] = 1;
  for(int j = 1; j <= 3; j++)
    for(int i = 0; i <= x; i++) {
        if(
    }
   for(int j = 1; j <= x; j++) {
       for(int i = 1; i <= 3; i++) printf("%3d", rj[j][i]);
       printf("\n"); 
   }       
   scanf("\n");
  return 0;
}   

