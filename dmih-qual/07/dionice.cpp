#include <cstdio>
#include <cmath>

int n, ulog, value[20];
bool novac;


int main() {
    novac = true;
    int n, Ulog, ulog, value[20], dion=0, max = 0;
    
    scanf("%d", &Ulog);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &value[i]);
    
    for(int bin = 0; bin < pow(2,n); bin++){
        ulog = Ulog;
        novac = true;
        for(int i = 0; i < n; i++){
            //printf("%d", (1 << i) & bin);
            if((1 << i) & bin) {
              if(novac){
                dion = ulog / value[bin];
                ulog = ulog % value[bin];
                }    
              else {
                ulog += dion * value[bin];
                dion = 0;
              }
            if(novac) novac=false;
            else novac = true;
            }    
            
            if(i == 7 && novac) max >?= ulog;
                
        }          
    }    
    printf("%d", max);
    scanf("\n");
    
    return 0;
}    
