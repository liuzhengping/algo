#include <cstdio>
#include <cstring>
#include <conio.h>
#include <ctype.h>
#include <cstdlib>
using namespace std;
struct slova {
    char ch;
    char niz[150];
    int br;
    int n_br;
    void add() {
        niz[br++] = '*';
    }    
} sl[26];
void init() {
    int i = 0;
    for(char c = 'a'; c <= 'z'; c++, i++) {
        for(int j = 0; j < 150; j++)
          sl[i].niz[j] = ' ';
        sl[i].ch = c;
        sl[i].br = 0;
    }        
}
void ispisi(int max) {
    for(int i = 0; i < 52; i++) printf("-");
    printf("\n");
    for(int i = max - 1; i >= 0; i--) {
        for(int j = 0; j < 26; j++) {
            printf("%c ", sl[j].niz[i]);
        }
        printf("\n");
    }
    for(int i = 0; i < 52; i++) printf("-");
    printf("\n");
    for(char c = 'a'; c <= 'z'; c++) printf("%c ", c);
    printf("\n");        
}        
int main() {
    char c, str[200];
    for(int puta = 1; puta <= 10; puta++) {
        int k  = 0;
        int max = 0;
        init();
        if(puta < 10) {
          printf("Line #%d: ", puta);
          while((c = getchar()) != '\n') 
              if(tolower(c) >= 'a' && c <= 'z')
                str[k++] = c; 
          str[k] = '\0';
          for(int i = 0; i < strlen(str); i++) {
              for(int j = 0; j < 26; j++) {
                  if(str[i] == sl[j].ch) {
                    if(puta <= 9) 
                      sl[j].add();
                    else
                      sl[j].br++;
                  }    
              }
          }
        }    
        for(int i = 0; i < 26; i++) sl[i].n_br += sl[i].br;
        if(puta == 10) {
            for(int i = 0; i < 26; i++) {
                sl[i].n_br /= 5;
                for(int j = 0; j < sl[i].n_br; j++)
                    sl[i].add();
            }    
        }    
        for(int i = 0; i < 26; i++) 
            if(sl[i].br > max)
              max = sl[i].br;
        printf("Output #%d:\n", puta);       
        ispisi(max); 
    }    
    getch();
    return 0;
}    
