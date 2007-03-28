#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#define MAX 10000000
using namespace std;
int a[MAX], a2[MAX], n;
void bubble() {
  bool flag;
  do {
    flag = false;
    for(int i = 1; i < n; ++i) if(a[i-1] > a[i]) {swap(a[i-1], a[i]); flag = true;}
  } while(flag); 
}
void selection() {
  for(int i = 0; i < n-1; ++i)
    for(int j = i; j < n; ++j)
      if(a[j] < a[i]) swap(a[i], a[j]); 
}
void quick1(int l, int r) {
  if(l < r) {
    int i, j;
    i = l-1; j = r;
    for(;;) {
      while(a[++i] < a[r]);
      while(a[--j] > a[r]);
      if(i >= j) break;
      swap(a[i], a[j]);
    }
    swap(a[i], a[r]);
    quick1(l, i-1);
    quick1(i+1, r);  
  }  
}
void quick2(int l, int r) {
  int s, i, j;
  s = (l+r)/2; i = l; j = r;
  for(;;) {
    while(a[i] < a[s]) ++i;
    while(a[j] > a[s]) --j;
    if(i > j) break;
    swap(a[i], a[j]);
    ++i; --j; 
  }
  if(l < j) quick2(l, j);
  if(i < r) quick2(i, r);  
}     
void init() {
  for(int i = 0; i < n; ++i) a[i] = a2[i];
}     
void ispis() {
  for(int i = 0; i < n; ++i) printf("%d ", a[i]);
  printf("\n");
}  
int main() {
  double st, kraj;
  srand(time(NULL));
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) a2[i] = i;
  /*init();
  st = clock();
  bubble();
  kraj = clock();
  printf(">%lf<\n", kraj-st);
  
  init();
  st = clock();
  bubble();
  kraj = clock();
  printf(">%lf<\n", kraj-st);*/
  /*init();
  st = clock();
  quick1(0, n);
  kraj = clock();
  printf(">%lf<\n", kraj-st);*/
  init();
  st = clock();
  quick2(0, n);
  kraj = clock();
  printf(">%lf<\n", kraj-st);
  /*init();
  st = clock();
  sort(a, a+n);
  kraj = clock();
  printf(">%lf<\n", kraj-st);*/
  scanf("\n");
  return 0;
}  
