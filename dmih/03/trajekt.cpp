#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 1440
#define INF 32767
using namespace std;
struct trajekt {int vr,sm; bool bio;} t[MAX];
void quicksort(int l, int r) {
    if(r > l) {
        int i, j, v;
        v = t[r].vr; i = l-1; j = r;
        for(;;) {
            while(t[--j].vr > v);
            while(t[++i].vr < v);
            if(i >= j) break;
            swap(t[i], t[j]);
        }
        swap(t[r], t[i]);
        quicksort(l, i-1);
        quicksort(i+1, r);  
    }
}             
int main() {
    int a, b, d, e, tm;
    scanf("%d %d", &a, &b);
    tm = a+b;
    scanf("%d", &d);
    for(int i = 0; i < d; i++) {
        int h, min;
        scanf("%d:%d", &h, &min);
        t[i].vr = h*60+min; t[i].sm = 0;
    }    
    scanf("%d", &e);
    int k = 0;
    for(int i = d; i < d+e; i++) {
        int h, min;
        scanf("%d:%d", &h, &min);
        t[i].vr = h*60+min; t[i].sm = 1;
    }
    int vel = d+e, vel_t = d+e;
    int sol = 0;
    while(vel) {
        sol++;
        quicksort(0, vel_t-1);
        vel_t = vel--;
        int tt = t[0].vr+tm;
        t[0].vr = INF;
        t[0].sm = 1 - t[0].sm;
        for(int i = 1; i < vel_t; i++)
            if(t[i].sm != t[0].sm && tt <= t[i].vr+tm) {
                vel--;
                tt = tm+t[i].vr;
                t[i].vr = INF;
                t[0].sm = 1 - t[0].sm;
            }        
    }       
    //for(int i = 0; i < d+e; i++) printf("%d\n", t[i].vr); 
    printf("%d", sol);
    scanf("\n");
    return 0;
}    
