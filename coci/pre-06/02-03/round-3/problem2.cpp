#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
    int n; char z[2], c; long int sol = 0;
    scanf("%d", &n); scanf("%s", &z); c = z[0];
    for(int i = 1; i <= n; i++) {
        char s[10];
        sprintf(s, "%d", i);
        for(int j = 0; j < strlen(s); j++)
          if(s[j] == c) sol++;
    }
    printf("%ld", sol);      
    
    int tmp; scanf("%d", &tmp);
    return 0;
}    
