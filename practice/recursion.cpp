#include <cstdio>
#include <iostream>
using namespace std;

double f(int x){
  if(x <= 1) return 1.0/2;
  return (double)x/(x+1) * f(x-1) +1;
  if(x % 2 && x > 0)return -1;
}  

int main(){
  printf("%lf %lf", f(6), 25.0/7);
  scanf("\n");
  return 0;
}


