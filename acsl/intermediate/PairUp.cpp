#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <string.h>
#include <vector.h>
#include <algorithm>
using namespace std;
struct gruop {
    char ch;
    vector<char> v;
    vector<char>::iterator iter;
    bool test(int i, char c) {
        iter = find(v.begin(), v.end(), c);
        if(iter != v.end())
          return true;
        return false;
    }     
} g[26];
void init() {
    int i = 0;
    for(char c = 'A'; c <= 'Z'; c++) {
      g[i].ch = c;
      g[i].v.clear();
      g[i++].v.push_back(c);
    }    
}
bool pairs(char a, char b) {
    int x, y;
    for(int i = 0; i < 26; i++) {
      if(g[i].test(i, a))
        x = i;
      if(g[i].test(i, b))
        y = i;
    }
    if(x == y)
      return 0;
    if(g[x].v.size() < g[y].v.size()) {
        g[y].v.insert(g[y].v.end(), g[x].v.begin(), g[x].v.end());
        g[x].v.clear();
    }
    else if(g[x].v.size() > g[y].v.size()) {
        int t = x;
        x = y;
        y = t;
        g[y].v.insert(g[y].v.end(), g[x].v.begin(), g[x].v.end());
        g[x].v.clear(); 
        t = x;
        x = y;
        y = t;
    }
    else {
        if(g[x].ch > g[y].ch) {
            g[y].v.insert(g[y].v.end(), g[x].v.begin(), g[x].v.end());
            g[x].v.clear();
        }
        else {
            int t = x;
            x = y;
            y = t;
            g[y].v.insert(g[y].v.end(), g[x].v.begin(), g[x].v.end());
            g[x].v.clear(); 
            t = x;
            x = y;
        }
    }
                               
}   
int main() {
    char str[51];
    char c;
    vector<char> max, rez;
    vector<char>::iterator iter;
    
    for(int puta = 1; puta <= 5; puta++) {
      init();
      max.clear(); rez.clear();
      printf("Line #%d: ", puta);
      int k = 0;
      while( (c = getchar()) != '\n') {
          if(c != ' ')
            str[k++] = c;
      }
      str[k] = '\0';
      for(k = 0; str[k] != '\0'; k+=2)  
          pairs(str[k], str[k+1]);
      for(int i = 0; i < 26; i++)
          max.push_back(g[i].v.size());
      sort(max.begin(), max.end(), greater<int>());
      for(int i = 0; i < 26; i++) 
          if(g[i].v.size() == max.front())
            rez.push_back(g[i].ch);
      sort(rez.begin(), rez.end());
      printf("Output #%d: ", puta);
      for(iter = rez.begin(); iter != rez.end(); iter++)
        cout << *iter << " ";
      cout << endl;  
    }    
    getch();
    return 0;
}    
          
