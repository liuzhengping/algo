#include <cstring>
#include <cstdio>
int stoi(char *s) {
    int n = strlen(s)-1;
    int suma = 0;
    for(int i = 1; n >= 0; i*=10, n--) {
        if(s[n] == '-') 
          return 0-suma;
        else 
          suma+= (i*(s[n]-'0'));
    }
    return suma;
}              
        
int main() {
    char str[10]; float br;
    scanf("%f", &br);
    sprintf(str, "%0.0f", br);
    printf("\n%d", stoi(str));
    int temp; scanf("%d", &temp);
    return 0;
}    
