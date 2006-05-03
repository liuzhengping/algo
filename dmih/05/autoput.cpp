#include <cstdio>
#include <cstdlib>
int v[100001], prev[100001], desno[100001], r[2][100001];
int main() {
    const int inf = 100005;
    int a, b, c, n, k; char ch, put[100001];
    int vmin = inf; 
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d %d", &n, &k);
    v[0] = 0;  scanf("%s", &put);
    for(int i = 1; i <= n; i++) {
        ch = put[i-1];
        if(ch == 'R') v[i] = v[i-1];
        else if(ch == 'D') v[i] = v[i-1]-1;
        else v[i] = v[i-1]+1;
        vmin <?= v[i];
    }
    if(vmin < 0)
      for(int i = 0; i <= n; i++) {v[i]-=vmin; r[0][i] = inf;}
    for(int i = 0; i <= n; i++) {
        if(prev[v[i]] && prev[v[i]] != i-1) {
            desno[prev[v[i]]] = i;
        }    
        prev[v[i]] = i;
    }
    int curr = 0, next = 1; int sol = inf; r[0][0] = 0;
    for(int j = 0; j <= k; j++) {
        for(int i = 0; i <= n; i++) r[next][i] = inf;
        for(int i = 0; i <= n; i++) {
          if(v[i+1] == v[i]+1) r[curr][i+1] <?= r[curr][i]+b;
          else if(v[i+1] == v[i]-1) r[curr][i+1] <?= r[curr][i]+b;
          else r[curr][i+1] <?= r[curr][i]+a;
          if(desno[i]) r[next][desno[i]] <?= r[curr][i]+(desno[i]-i)*c; 
        }
        sol <?= r[curr][n];  
        curr ^= 1; next ^= 1;
    }
    printf("%d", sol);     
    scanf("%d", &vmin);
    return 0;
}    
