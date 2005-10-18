#include <cstdio>
#include <ctime>
#define MAX (long long)1E7/2
long long int prime[MAX];
int main() {
    double start = clock();
    for(long long int i = 2; i*i <= MAX; i++) {
        if(prime[i]) continue;
        for(long long int j = i; j*i < MAX; j++) 
            prime[i*j] = 1;
    }
    //for(int i = 1; i < MAX; i++) if(!prime[i]) printf("%d ", i);
    printf("%lf ms\t Interval od 1 do %lld\n", clock()-start, MAX); 
    for(;;) {
        long long int a;
        scanf("%lld", &a);
        if(!a) break; 
        if(!prime[a]) printf("\n%d je prost broj.", a);
        else printf("\n%d nije prost broj.", a);
    }    
    printf("Gotovo!");
    return 0;
}    
        
          
