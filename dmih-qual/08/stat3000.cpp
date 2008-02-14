#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int main() {
  int last = 0;
  vector<int> e;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    int h, m, s;
    char buff[20];
    scanf("%s", buff);
    scanf("%d:%d:%d", &h, &m, &s);
    s += m*60 + 3600*h;
    while(s < last) s += 24*3600;
    if(buff[0] == 'P')  e.push_back(s);
    else if(buff[0] == 'U') {
      int a = 0, b = 0;
      for(int j = 0; j < e.size(); ++j) {
        if(s-e[j] <= 60) ++a;
        if(s-e[j] <= 3600) ++b;
      }  
      printf("%d %d %d\n", e.size(), b, a);
    } 
    last = s; 
  }  
  scanf("\n");
  return 0;
}

/*
4
P 09:20:00
P 09:30;00
U 10:00:00
U 10:25:00

*/
