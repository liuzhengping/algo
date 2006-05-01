#include <cstdio>
#include <cstdlib>
#define MAX 10001
int x[MAX], lijevo[MAX], desno[MAX];
long suma[MAX];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
    }
    for(int i = 1; i <= n; i++) {
        desno[i] = lijevo[i] = 0;
        suma[i] = suma[i-1]+x[i];
    }    
    for(int i = 1; i < n;) {
       if(x[i] > x[i+1]) {
        int j;
        for(j = i+1; j <= n; j++) 
         if(x[j] >= x[i]) {desno[i] = j; break;}   
        i = j;
       }
       else i++;    
    }    
    for(int i = n; i >= 1;) {
        if(x[i] > x[i-1]) {
            int j;
            for(j = i-1; j >= 0; j--)
              if(x[j] >= x[i] && desno[j] != i) {lijevo[i] = j; break; }
            i = j;
        }
        else i--;    
    } 
    long sol = 0;
    for(int i = 1; i <= n; i++) {
        if(desno[i]) sol+=x[i]*(desno[i]-i-1) - (suma[desno[i]-1]-suma[i]); 
        else if(lijevo[i]) sol+=x[i]*(i-lijevo[i]-1) - (suma[i-1]-suma[lijevo[i]]);
    }          
    printf("%ld", sol);
    scanf("\n");
    return 0;
}



