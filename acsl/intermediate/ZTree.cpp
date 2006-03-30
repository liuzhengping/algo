#include <cstdio>
#include <cstring>
char x[100000];
void init() {
    for(int i = 0; i < 100000; i++) x[i] = '-';
}
void visit(int node) {
    if(x[node*2+1] != '-') visit(node*2+1);
    printf("%c ", x[node]);
    if(x[node*2+2] != '-') visit(node*2+2);
}        
int main() {
    char str[51];
    for(int puta = 1; puta <= 5; puta++) {
        init();
        printf("Line #%d: ", puta);
        scanf("%s", &str);
        x[0] = str[0];
        for(int i = 1; i < strlen(str); i++) {
          int a = 0;
          for(bool br = 0;;br=1-br) {
              if(x[a] == '-') {x[a] = str[i]; break; }
              else if(str[i] > x[a] ^ br) a = 2*a+2;
              else a = a*2+1;
          } 
        }
        printf("Output #%d: ", puta);
        visit(0);       
        printf("\n"); 
    }    
    return 0;
}    
