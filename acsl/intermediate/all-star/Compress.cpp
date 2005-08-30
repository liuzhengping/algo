#include <string.h>
#include <stdio.h>
#include <iostream.h>
#include <algorithm>
#include <conio.h>
using namespace std;
struct slova {
    char ch;
    int occ;
} sl[26];
void init() {
    char c;
    for(int i = 0, c = 'a'; i < 26; i++, c++) {
        sl[i].ch = c;
        sl[i].occ = 0;
    }    
}       
int main() {
    char c, str[128];
    int br = 0;
    
    init();
    while ((c=cin.get()) != '\n')
      str[br++] = c;
    str[br] = '\0';
    string s(str, strlen(str));
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') s[i] = '*';
        for(int j = 0; j < 26; j++) {
            if(sl[j].ch == s[i]) {
              sl[j].occ++;
              if(sl[j].occ != 1 &&  sl[j].occ != 3  && sl[j].occ != 6) {
                  s[i] = ' ';
                  
              }
            }        
        }
    }
    for(int i = 0; i < s.size(); i++)
      if(s[i] != ' ') cout << s[i];
    getch();
    return 0;
}    
