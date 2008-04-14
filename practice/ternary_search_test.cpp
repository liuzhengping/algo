#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 76
using namespace std;
int n, hill;
vector<int> a;
int f(int x) { return x*x-26*x+3; }
int provjera(int x) {
  return binary_search(a.begin(), a.begin()+hill, x) 
    | binary_search(a.begin()+hill, a.end(), x, greater<int>());
}  
int ts() {
  double lo = 0, hi = n;
  for(int itr = 0; itr < 100; ++itr) {
    double lt = lo + (hi-lo)/3;
    double rt = lo + 2*(hi-lo)/3;
    if(f((int)lt) < f((int)rt)) {
      hi = rt;
    }  
    else lo = lt;
  }
  return (int)(lo + hi)/2;  
}  
int brute() {
  int ret = 1000000000, where = -1;
  for(int i = 0; i <= n; ++i) {
    int curr = f(i);
    printf("(%d)", curr);
    if(curr < ret) {
      ret = curr;
      where = i;
    }  
  } 
  return where; 
}  
void postavi() {
  srand(time(0));
  a.resize(n);
  for(int i = 0; i < n; ++i)
    a[i] = rand()%MAX;
  hill = rand()%n;
  sort(a.begin(), a.begin()+hill);
  sort(a.begin()+hill, a.end(), greater<int>());
  for(int i = 0; i < n; ++i)
    printf("%d ", a[i]);
}
int main() {
  n = 100;
  printf("ts: %d\n", ts());
  printf("Brute: %d\n", brute()); 
  /*scanf("%d", &n);
  postavi();
  for(;;) {
    int x;
    scanf("%d", &x);
    printf("->%d\n", provjera(x));
  }  */
  scanf("\n");
  return 0;
}


