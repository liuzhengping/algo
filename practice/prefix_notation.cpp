#include <set.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
bool isop(char c) {return c == '+' || c == '-' || c == '*' || c == '/';}
string f(char *s, int ind) {
    string o;
    for(int i = ind; i < strlen(str)-1; i++) {
        if(isop(s[i])) {op = s[i]; o = f(i+1); }
        else if(!isop(s[i+1])) {
          string s2; s2.append(s[i]); s2.append(s[i+1]);
          return s2;
        }
        else o1 = s[i];
    }
}        
int main()  {
    char str[100];
    scanf("%s", &str);
    f(0);
    int tmp; scanf("%d", &tmp);
    return 0;
}    
