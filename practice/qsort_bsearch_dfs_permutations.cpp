#include <cstdio>
#include <cstring>
int id = 0, v = 4, val[10];
void writeperm() {for(int i = 0; i < v; i++) printf("%d ",val[i]); printf("\n");}               
int bs(int *a, int l, int r, int v) {
    while(l <= r) {
        int x = (l+r)/2;
        if(a[x] == v) return x+1;
        else if(a[x] < v) l = x+1;
        else r = x-1;
    } 
    return -1;
}
int qs(int *a, int l, int r) {
    if(l < r) {
        int v, i, j, t;
        v = a[r]; j = r; i = l-1;
        for(;;) {
            while(a[++i] < v);
            while(a[--j] > v);
            if(i >= j) break;
            t = a[j]; a[j] = a[i]; a[i] = t;
        }
        t = a[i]; a[i] = a[r]; a[r] = t;
        qs(a, l, i-1);
        qs(a, i+1, r);
    }            
}
void init() {
    for(int i = 0; i < v; i++) val[i] = 0;
}
void perm(int k) {
    val[k] = ++id;
    if(id == v) writeperm();
    for(int i = 0; i < v; i++) if(val[i] == 0) perm(i);
    val[k] = 0; id--;
}
void ha() {
    float a = 0.526;
    printf("\n\n%f", a);
}     
int main() {
    int a[10] = {1,2,3,4,5,6,8,8,9,10};
    int b[10] = {10,9,8,8,6,5,3,3,3,1};
    for(int t; t != 0; scanf("%d", &t), printf("\n%d",bs(a, 0, 9, t))) ;
    //qs(b,0,9); init(); perm(0);
    ha();
    for(int i = 0; i < 10; i++) printf("%d ", b[i]);
    scanf("%d", &a[0]);
    return 0;
}    
