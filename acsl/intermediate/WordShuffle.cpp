#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <vector.h>
#include <ctype.h>
using namespace std;
bool number(char *s) {
    for(int i = 0; i < strlen(s); i++)
        if(isdigit(s[i]))
          return true;    
    return false;
}    
int main() {
    char str[100], c, *podniz;
    for(int puta = 1; puta <= 5; puta++) {
      printf("Line #%d: ", puta);
      int br = 0;
      vector<string> s;
      vector<string>::iterator end, iter;
      while(( c = cin.get()) != '\n') {
          if(!ispunct(c))
            str[br++] = c;
      }
      str[br] = '\0';
      podniz = strtok(str, " ");
      if(podniz) {
          do {
              if(!number(podniz))
                s.push_back(podniz);
              podniz = strtok(NULL, " ");
          } while(podniz);
      }
      sort(s.begin(), s.end());
      end = unique(s.begin(), s.end());
      s.erase(end, s.end());
      sort(s.begin(), s.end());
      printf("\nOutput #%d: ", puta);
      for(iter = s.begin(); iter != s.end(); iter++)
        cout << *iter << " ";
      cout << endl;
    }            
    getch();
    return 0;
}    
