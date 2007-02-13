#include <cstdio>
#include <iostream>
using namespace std;
#define MAX 104
int r, s, n, visina[MAX], dp[4][MAX], zadnji, ljestve[MAX];
int main() {
    scanf("%d %d", &s, &r);
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        visina[a] >?= b; //u kojem stupcu je zadnja polica koju treba doseci
        zadnji >?= a;  //bitna je samo najvisa polica u nekom stupcu
    }
    int prek = 3, sa = 2, bez = 1, ne = 0;
    //prek = ljestve prolaze kroz taj, moraju moci uzet jos i iz prethodnog
    //da = ljestve prolaze kroz taj stupac
    //bez = ljestve ne prolaze kroz taj stupac nego prethodni
    //ne = ljestve ne prelaze kroz taj, a ljestvo kroz prethodni su nize
    //ljestve[x] = duljina ljestva koje prolaze kroz neki stupac ali da mogu pokupit iz prethodnog
    if(visina[1]) dp[bez][1] = dp[prek][1] = dp[sa][1] = ljestve[1] = visina[1];
    for(int curr = 2; curr <= zadnji; ++curr) {
        if(visina[curr] < visina[curr-1]) {
            dp[ne][curr] = dp[bez][curr-1];
            dp[bez][curr] = dp[sa][curr-1]; 
            dp[sa][curr] = min( dp[bez][curr-1]+visina[curr], dp[sa][curr-1]+visina[curr]);
            dp[prek][curr] = dp[ne][curr-1] + visina[curr-1];
            ljestve[curr] = visina[curr-1];
        }
        else {
            dp[ne][curr] = dp[bez][curr-1];
            if(visina[curr] > visina[curr-1]) 
              dp[ne][curr] = min(dp[ne][curr], dp[sa][curr-1]); 
            dp[bez][curr] = dp[prek][curr-1]+ max(visina[curr]-ljestve[curr-1], 0);
            dp[sa][curr] = min(dp[ne][curr-1] + visina[curr], dp[bez][curr-1]+visina[curr]);
            dp[sa][curr] = min( dp[sa][curr], dp[sa][curr-1]+visina[curr]);
            dp[prek][curr] = dp[sa][curr];
            ljestve[curr] = visina[curr];
            
        }
        //printf("%d\t%d\t%d\t%d\n", dp[ne][curr], dp[bez][curr], dp[sa][curr], dp[prek][curr]);        
    }
    int sol = min(dp[prek][zadnji], dp[sa][zadnji]);
    sol = min(sol, dp[bez][zadnji]);
    printf("%d", sol);        
    scanf("\n");
    return 0;
}  
/*
10 10
10
1 5
2 7
3 4
4 7
5 5
7 5
7 7
8 2
8 8
9 8
*/  
