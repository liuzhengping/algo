#include <cstdio>
#include <iostream>
using namespace std;
int a[3][3], backup[3][3], r[3], c[3]; 
int ok() {
  memset(r, 0, sizeof r);
  memset(c, 0, sizeof c);
  for(int i = 0; i < 3; ++i)
    for(int j = 0; j < 3; ++j) {
      c[j] += a[i][j];
      r[i] += a[i][j];
    }

  int sum = r[0];
  for(int i = 0; i < 3; ++i)
    if(r[i] != sum || c[i] != sum)
      return 0;
  return sum == a[0][0]+a[1][1]+a[2][2] && sum == a[0][2]+a[1][1]+a[2][0];
}  
void work() {
  for(int i1 = 0; i1 < 3; ++i1)
    for(int j1 = 0; j1 < 3; ++j1)
      for(int i2 = 0; i2 < 3; ++i2)
        for(int j2 = 0; j2 < 3; ++j2) 
          for(int n1 = 0; n1 <= 9; ++n1)
            for(int n2 = 0; n2 <= 9; ++n2) {
              memcpy(a, backup, sizeof backup);
              a[i1][j1] = n1;
              a[i2][j2] = n2;
              if( ok() )
                return;
           }  
}  
int main() {
  char buff[5];
  for(int i = 0; i < 3; ++i) {
    scanf("%s", &buff);
    for(int j = 0; j < 3; ++j)
      backup[i][j] = a[i][j] = buff[j] - '0';
  } 
  work();
  for(int i = 0; i < 3; ++i, printf("\n"))
    for(int j = 0; j < 3; ++j)
      printf("%d", a[i][j]);

  return 0;
}


