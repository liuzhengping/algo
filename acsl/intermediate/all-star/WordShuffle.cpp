#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <vector.h>
#include <ctype.h>
#include <algorithm>
#include <functional>
using namespace std;
bool number(char *s) {
    for(int i = 0; i < strlen(s); i++)
        if(isdigit(s[i]))
          return true;    
    return false;
}
vector<string> sort_l(vector<string> v) {
    for(int i = 0; i < v.size() - 1; i++) 
      for(int j = i+1; j < v.size(); j++)
        if(v[j].size() > v[i].size()) {
            string t = v[i];
            v[i] = v[j];
            v[j] = t;
        }
    return v;
}
vector<string> sort_rev(vector<string> v, int a, int b) {
    vector<string> v2;
    pair<vector<string>::iterator, vector<string>::iterator> par;
    par.first = find(v.begin(), v.end(), v[a]);
    if(par.first == v.end()) par.first = v.begin();
    if(b != v.size()) 
      par.second = find(v.begin(), v.end(), v[b]);
    else
      par.second = v.end();
    if(par.second == v.end()) par.second = v.end();
    //getch(); printf("(%d,%d)", a, b);
    for(int i = a; i < b; i++)  
      v2.push_back(v[i]); 
    sort(v2.begin(), v2.end());
    reverse(v2.begin(), v2.end());
    //for(vector<string>::iterator iter = v2.begin(); iter != v2.end(); iter++)
      //  cout << *iter << " ";
    v.erase(par.first, par.second);
    v.insert(par.first, v2.begin(), v2.end());
    return v; 
}                  
int main() {
    char str[100], c, *podniz;
    int ozn[100];
    for(int puta = 1; puta <= 5; puta++) {
      for(int i = 0; i < 100; i++) ozn[i] = -1;
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
      s = sort_l(s);
      br = 1;
      int len = s[0].size();
      ozn[0] = 0;
      for(int i = 0; i < s.size(); i++) {
          if(len != s[i].size()) {
              len = s[i].size();
              ozn[br++] = i;
          }
      }
      ozn[br] = s.size();
      
      cout << endl;
      for(int i = 0; i < br; i++) {
          
        s = sort_rev(s, ozn[i], ozn[i+1]);
      }    
      printf("\nOutput #%d: ", puta);
      for(iter = s.begin(); iter != s.end(); iter++)
        cout << *iter << " ";
      cout << endl;
    }            
    getch();
    return 0;
}    
