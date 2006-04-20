#include <cstdio>
#include <cmath>
#include <cstdlib>
int main() {
    int x = 0, y = 0, tx, ty, k;
    char str[100001];
    scanf("%d %d", &x, &y); tx = 0; ty = 0;
    scanf("%d", &k);
    scanf("%s", &str);
    bool da = false;
    if(abs(tx-x) <= 1 && abs(ty-y) <= 1) {printf("%d\n", 0); da = true; }
    for(int i = 0; i < k; i++) {
        if(str[i] == 'J') ty++;
        else if(str[i] == 'S') ty--;
        else if(str[i] == 'I') tx++;
        else if(str[i] == 'Z') tx--;       
        if(abs(tx-x) <= 1 && abs(ty-y) <= 1) {da = true; printf("%d\n", i+1);}
    }
    if(!da) printf("-1");    
    scanf("\n");
    return 0;
}        
