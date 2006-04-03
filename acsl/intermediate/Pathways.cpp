#include <cstdio>
int polje[100][100];
int susj[4][2] = {-1,0,0,-1,1,0,0,1};
bool bio[100][100]; int x2, y2;
int dp[100][100];
//1 1 1 2 1 3 1 4 1 5 2 1 2 2 2 3 2 4 2 5 3 1 3 2 3 3 3 4 3 5 4 1 4 2 4 3 4 4 4 5 5 1 5 2 5 3 5 4 5 5 0 0
long int visit(int y, int x) {
    if(y == y2 && x == x2) return 1;
    //else if (dp[y][x] != -1) return dp[y][x];
    bio[y][x] = true;
    int r = 0;
    for(int i = 0; i < 4; i++)
      if(y+susj[i][0] >= 1 && x+susj[i][1] >= 1)
        if(polje[y+susj[i][0]][x+susj[i][1]])
          if(!bio[y+susj[i][0]][x+susj[i][1]])
            r+=visit(y+susj[i][0],x+susj[i][1]);
    bio[y][x] = false;
    return dp[y][x] = r;
}    
void init() {
    for(int i = 0; i < 100; i++)
       for(int j = 0; j < 100; j++) {
          bio[i][j] = false; dp[i][j] = -1;
       }
}
int main() {
    long int sol;
    int x1, y1;
    for(int a, b;;) {
        scanf("%d %d", &a, &b);
        if(!a || !b) break;
        polje[a][b] = 1;
    }
    for(int i=0; i < 5; i++) {
        init();
        printf("%d. ", i+2);
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
        sol = visit(y1,x1);
        if(sol) printf("%d. %d\n",i+1,sol);
        else printf("%d. NONE\n",i+1);
    }            
    return 0;
}    
