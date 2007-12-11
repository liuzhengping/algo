#include <cstdio>
#include <iostream>
using namespace std;
int main(){
  for(int i=0;i<5;i++) {
    float a[3], b[3], c[6];
    for(int i = 0; i < 3; ++i) scanf("%f", &a[i]);
    for(int i = 0; i < 3; ++i) scanf("%f", &b[i]);
    sort(a, a+3);
    sort(b, b+3);
    printf("%d\n", set_intersection(a, a+3, b, b+3, c) - c );
  } 
  scanf("\n"); 
  return 0;
}


