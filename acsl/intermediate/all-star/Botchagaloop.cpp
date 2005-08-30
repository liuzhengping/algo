#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <iostream.h>
using namespace std;
static int br = 0;
void oct(char *str, int x) {
        long int rem;
        rem = x%8;
        x/=8;
        if(x > 0)
          oct(str, x);
        str[br++] = rem + '0';
}
 
void sortiraj(char *s) {
    for(int i = 0; i < strlen(s)-1; i++) {
        for(int j = i+1; j < strlen(s); j++) {
            if(s[i] > s[j]) {
                char t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
        }
    }            
}
long int dec(char *s) {
    long int suma = 0;
    int j;
    for(int i = strlen(s) - 1, j = 1; i >= 0; i--, j*=8)  
      suma+= ((s[i] -'0') * j);
    return suma;  
}         
int main() {
    long int p, x, q;
    char str[10], sort[10];
    scanf("%ld", &x);
    /*while(x > 0) {
        rem = x%8;
        x/=8;
        str[br++] = rem + '0';
    }*/
    p = x;
    
    for(int i = 0; i < 5; i++) {
      bool da = 1; 
      br = 0;
      oct(str, p);
      str[br] = '\0';
      strcpy(sort, str);
      sortiraj(sort);
      q = dec(sort);
      p-=q;
      char temp[10];
      br = 0;
      oct(temp, p);
      temp[br] = '\0';
      for(int i = 0; i < strlen(temp)-1; i++) 
          if(temp[i] > temp[i+1])
            da = 0;
      if(da == 1)
        break;
          
    }           
    printf("%d", p);
    getch();
    return 0;
}    
