#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
double c, k, x; int g, m;
void solve() {
  double sol = c/pow(1+k, m);
  sol = floor(sol*100)/100;
  if(sol*pow(1+k, m) < c) sol+=.01;
  printf("%.2lf", sol);  
}  
void input() {
  scanf("%lf", &c); 
  scanf("%lf", &k); k/= 100;
  scanf("%d %d", &g, &m); m += g*12; 
}  
int main() {
  input();
  solve();
  scanf("\n");
  return 0;
}  
