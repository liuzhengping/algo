#include <cstdio>
#include <cstdlib>
#include <vector.h>
#include <iostream.h>
#define MAX 5
int val[MAX], red[MAX]; int id = 0;
int polje[MAX][MAX], nep[MAX];
int N, M, count = 0, da = 0;
vector<int> v;
int broji() {
    int br = 0;
    for(int i = 0; i < N; i++) 
       for(int j = 0; j < N; j++) 
           if(polje[i][j]) val[i]++;
    for(int i = 0; i < N; i++)
        if(val[i]%2) nep[br++] = i;
    if(br > 2) {
        printf("Nemoguce!"); scanf("%d", &br);
        exit(0);
    }
    return br;    
}    
int visit(int k) {
    red[k] == ++id;
    v.push_back(k+1); count++;
    if(id == M+1) { 
        vector<int>::iterator it;
        if(da)
          v.erase(v.begin()+(9-count), v.begin()+9);
        for(it = v.begin(); it != v.end(); it++) cout << *it << " ";
        printf("\n");
        //cin.get();
        count = 0;
        da = 1;
    }    
    for(int i = 0; i < N; i++) {
        if(polje[k][i] && (val[i] > 1 || id == M)) {
            polje[k][i] = 0; polje[i][k] = 0; 
            val[k]--; val[i]--;
            visit(i);
            polje[k][i] = 1; polje[i][k] = 1; 
            val[k]++; val[i]++;
        }
    }
    red[k] = 0; id--;
}            
int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        polje[--a][--b] = 1; polje[b][a] = 1;
    }
    int br_nep = broji(); printf("%d\n", br_nep);
    visit(nep[0]);    
    int tmp; scanf("%d", &tmp);
    return 0;
} 
/*
5 8
1 2
1 4
2 3
1 3
2 4
3 4
4 5
3 5*/   
