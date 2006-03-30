#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char x1[100000], x2[100000];
void init() {
    for(int i = 0; i < 100000; i++) x1[i] = x2[i] = '-';
}
void visit(int node) {
     printf("%c ", x1[node]);
    if(x1[node*2+1] != '-') visit(node*2+1);
    if(x1[node*2+2] != '-') visit(node*2+2);
}        
int main() {
    char str[51];
    for(int puta = 1; puta <= 5; puta++) {
        init();
        printf("Line #%d: ", puta);
        int k = 0; char c;
        while((c = cin.get()) != '\n') if(c != ' ') str[k++] = c;
        str[k] = '\0';
        x1[0] = str[0]; x2[0] = str[1];
        for(int i = 2; i < strlen(str); i++) {
          int a = 0, b = 0, br1, br2;
          for(br1 = 0; x1[a] != '-' ;br1++) {
              if(str[i] > x1[a]) a = 2*a+2;
              else a = a*2+1;
          }
          for(br2 = 0; x2[b] != '-'; br2++) {
              if(str[i] > x2[b]) b = 2*b+2;
              else b = b*2+1;
          }
          if(br1 <= br2) x1[a] = str[i];
          else x2[b] = str[i];     
        }
        printf("Output #%d: ", puta);
        visit(0);       
        printf("\n"); 
    }    
    return 0;
}    
