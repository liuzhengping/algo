#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <conio.h>
#include <vector.h>
#include <ctype.h>
using namespace std;
bool broj(char *s) {
    for(int i = 0; i < strlen(s); i++) {
        if(isdigit(s[i]))
          return 1;
    }
    return 0;
}              
int main(void) {
    char c, str[200], *podniz;
    vector<string> niz;
    for(int puta = 1; puta <= 5; puta++) {
      printf("Line #%d:", puta);  
      int i = 0;
      while((c = getchar()) != EOF && c != '\n') {
          if(!ispunct(c)) str[i++] = c;
      }
      str[i] = '\0';
      podniz = strtok(str, " ");
      if(podniz) {
          do {
              if(!broj(podniz))
                niz.push_back(podniz);
              podniz = strtok(NULL, " ");
          } while(podniz);
      }
      sort(niz.begin(), niz.end());
      vector<string>::iterator un;
      un = unique(niz.begin(), niz.end());
      int counter = 0;
      for(vector<string>::iterator iter = niz.begin(); iter != un; iter++)
          counter++;
      printf("Output #%d: %d\n", puta, counter);
      niz.clear();
    }    
    getch();
    return 0;
}        
    
                
