#include <stdio.h>
#include <conio.h>
#include <string.h>
using namespace std;
int main() {
    int N, a[1000], br = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);
    char str[1000];
    int j;
    for(j = 0; j < N; j++) str[j] = a[j]+'0';
    str[j] = '\0';
    int pos, temp;
    temp = 0;
    for(int k = 1; k <= N; k++) {
        for(pos = 0; pos < strlen(str); pos++)  
          if(k+'0' == str[pos]) break; 
        if(temp > pos) {
            br++;
            
        }
        temp = pos;
    }          
    printf("%d", br); 
    getch();
    return 0;
}           
