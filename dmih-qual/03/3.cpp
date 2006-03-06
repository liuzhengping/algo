#include <cmath>
#include <cstdio>
#include <iostream.h>
struct str {
    int x; int y;
    bool bio[100];
    int brl;
    int brst;
} lok[20], neb[100];    
int main() {
    int K, R, M, N, X, Y;
    scanf("%d %d", &K, &R);
    scanf("%d", &M);
    for(int i = 0; i< M; i++) scanf("%d %d", &lok[i].x, &lok[i].y);
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d %d %d", &neb[i].x, &neb[i].y, &neb[i].brst);
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if((sqrt((neb[j].x-lok[i].x)*(neb[j].x-lok[i].x)+
            (neb[j].y-lok[i].y)*(neb[j].y-lok[i].y)) ) <= R) {
                lok[i].bio[j] = true; neb[j].brl++; 
                lok[i].brst+=neb[j].brst;
            }    
                 
        }
    }
   for(int j = 0; j < N; j++) {
     if(neb[j].brl > 1)
       for(int i = 0; i < M; i++) {
           if(lok[i].bio[j]) {
               lok[i].brst-=neb[j].brst;
               lok[i].brl = 1;
           }
       } 
   }           
    for(int i = 0; i < K; i++) {
        if(lok[i].brl)
          for(int j = 0; j < N; j++) {      
    for(int i = 0; i < M-1; i++)
       for(int j = i+1; j < M; j++) 
           if(lok[j].brst > lok[i].brst) {
            str tmp =  lok[j];
            lok[j] = lok[i];
            lok[i] = tmp;
           }
     
    long int suma = 0;          
    for(int i = 0; i < K; i++) suma+= lok[i].brst;
    printf("%ld", suma);     
    scanf("%d",&R);
    return 0;
}    
