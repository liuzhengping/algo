#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char bar[102];
int n;
void init() {
    for(int i = 0; i < 101; i++) bar[i] = '?';
    bar[101] = '\0';
}
int rek(int pos) {
    for(int i = pos; bar[i] == '?'; i++);
}        
int main() {
    char tmp[102];
    init();
    scanf("%d", &n);
    for(int i = 0; i < 5; i++) {
        scanf("%s", &tmp);
        for(int i = 0; i < strlen(tmp); i++)
          if(tmp[i] != '?' && bar[i] == '?') bar[i] = tmp[i];
    }
    bar[n] = '\0';
    //for(int i = 0; i < n; i++) if(bar[i] == '?') rek(i);
    printf("%s", bar);   
    scanf("%s", &tmp);
    printf("%d", strstr(bar, tmp)); 
    scanf("\n");
    return 0;
}    
