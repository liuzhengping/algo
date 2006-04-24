#include <cstdio>
using namespace std;
int main() {
    int n, pot = 0, t2 = 0, tre = 0;
    int p[100000][2];
    p[0][0] = 0;
    scanf("%d", &n);
    for(int i = i; i <= n; i++) {
        scanf("%d %d", &p[i][0], &p[i][1]);
        t2+=pj[i][0];
        tre+=pj[i][1];
        pot = max(pot+pj[i-1][0], tre);
    }    
    printf("%d", pot+pj[n][0]-t2);
    scanf("\n");
    return 0;
}    
