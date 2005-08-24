#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <iostream.h>
int main() {
    char matrix[6][6] = {'1','2','3','4','5','4',
                         '2','5','4','3','2','1',
                         '3','5','3','4','5','1',
                         '4','4','3','4','5','2',
                         '5','3','4','3','4','3',
                         '1','4','5','2','3','4'};
    char str[10], s[10];
    int vel, x, y;
    for(int puta = 1; puta <= 5; puta++) {
      printf("Line #%d: ", puta);  
      scanf("%s", str);    
      printf("Output #%d: ", puta);
      vel = strlen(str);
      for(int i = 0; i < 6; i++) {
          for(int j = 0; j < 6; j++) {
              if(matrix[i][j] == str[0]) {
                  if(vel + j <= 6) {
                    s[0] = matrix[i][j];
                    for(x = 1; x < vel; x++) 
                       s[x] = matrix[i][j+x];
                    s[x] = '\0';
                    if(strcmpi(s, str) == 0) 
                      printf("%d,%d,east; ", i+1, j+1);
                  } 
                  if(vel + i <= 6) {
                    s[0] = matrix[i][j];
                    for(y = 1; y < vel; y++) 
                        s[y] = matrix[i+y][j];
                    s[y] = '\0';
                    if(strcmpi(s, str) == 0) 
                      printf("%d,%d,south; ", i+1, j+1);
                  }
                  if(i - vel + 1 >= 0) {
                    s[0] = matrix[i][j];
                    for(y = 1; y < vel; y++) 
                        s[y] = matrix[i-y][j];
                    s[y] = '\0';
                    if(strcmpi(s, str) == 0) 
                      printf("%d,%d,north; ", i+1, j+1);
                  }
                  if(j - vel + 1>= 0) {
                    s[0] = matrix[i][j];
                    for(x = 1; x < vel; x++) 
                        s[x] = matrix[i][j-x];
                    s[x] = '\0';
                    if(strcmpi(s, str) == 0) 
                      printf("%d,%d,west; ", i+1, j+1);
                  } 
                              
              }
          }
      }
      printf("\n");
    }                 
    getch();
    return 0;
}    
