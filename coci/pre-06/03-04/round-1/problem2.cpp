#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
    char str[202], sol[101];
    char c;
    int k = 0;
    while((c = cin.get()) != '\n')
      str[k++] = c;
    str[k] = '\0';
    for(k = 0; k+1 < strlen(str); k++)
      sol[(str[k+1]-'0')-1] = str[k];
    sol[strlen(str)/2] = '\0';
    printf("%s", sol);
    return 0;
}    
    
      
    
    
         
