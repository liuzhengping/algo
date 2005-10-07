#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    char str[101];
    int suma = 0, k = 0, sol;
    scanf("%s", &str);
    for(int i = 0; i < strlen(str); i++)
      suma+=(str[i]-96);
    suma/= 2;
    for(sol = 0; sol < strlen(str); sol++) {
        k+=(str[sol]-96);
        if(suma == k) {
          printf("iza ");
          break;
        }    
        else if(suma < k) {
          printf("na ");    
          break; 
        }    
    }
    printf("%d\t", sol+1);       
    printf("%d", suma);
    //scanf("%d", &suma);
    return 0;
}    
