#include <cstdio>
#include <ctime>
#include <algorithm>
#include <vector>
#define OUT "quick_out.txt"
#define IN "quick_in.txt"
using namespace std;
FILE *in, *out;
int polje[1000000];
int comp;
void quicksort(vector<int> a, int l, int r) {
    int v, i, j, t;
    if(r > l) {
          comp++;
        v = a[r]; i = l-1; j = r;
        for(;;) {
            while(a[++i] < v) ;
            while(a[--j] > v) ;
            if(i >= j) break;
            t = a[i]; a[i] = a[j]; a[j] = t;
        } 
        t = a[i]; a[i] = a[r]; a[r] = t;
        quicksort(a, l, i-1);
        quicksort(a, i+1, r);
    }
}   
/*void print(int node) {
    if(polje[node*2+1] != -1)
      print(node*2+1);
    printf("%d", polje[node]);
    if(polje[node*2+2] != -1)
      print(node*2+2);
}     */         
int main() {
    vector<int> niz;
    int n;
    in = fopen(IN, "r");
    out = fopen(OUT, "w");
    fscanf(in, "%d", &n);
    for(int i = 0; i < n; i++) niz.push_back(i);
    random_shuffle(niz.begin(), niz.end());
    
    int node, a;
    for(int i = 0; i < 999999; i++) polje[i] = -1;
    double start = clock(); comp = 0;
    for(int i = 0; i < n-1; i++) {
      for(int j=i+1; j < n; j++) {
          if(niz[j] < niz[i]) {
              int temp = niz[j];
              niz[j] = niz[i];
              niz[i] = temp;
          }  
      }
    }        
     random_shuffle(niz.begin(), niz.end());
     fprintf(out, "\n Selection - %lf ms, %d comp.", clock()-start, comp);
    polje[0] = niz[0];
    for(int j = 1; j < niz.size()-1; j++) {
        a = niz[j];
        node = 0;
        while(polje[node] != -1) {
            if(a <= polje[node])
              node=node*2+1;
            else
              node=node*2+2;
            comp++;
        }    
        polje[node] = a; 
    }
    fprintf(out, "\n Binary - %lf ms, %d comp.", clock()-start, comp);
    comp = 0;
    start = clock();
    quicksort(niz, 0, n-1);
    //for(int i = 0; i < n; i++) fprintf(out, "%d ", niz[i]);
    fprintf(out, "\n Quicksort - %lf ms, %d comp.", clock()-start, comp);
    random_shuffle(niz.begin(), niz.end());
    comp = 0;
    start = clock();
    sort(niz.begin(), niz.end());
    fprintf(out, "\n STL Sort - %lf ms, %d comp.", clock()-start, comp);

    fclose(out);
    fclose(in);
    return 0;
}    
    
    
    
