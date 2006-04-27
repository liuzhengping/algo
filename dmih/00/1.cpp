#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
char niz[] = {'a','e','i','o','u','b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
vector<string> v;
void pretvori(char *s) {
    for(int i = 0; i < strlen(s); i++) {
        for(int j = 0; j < strlen(niz); j++)
            if(s[i] == niz[j]) {s[i]='a'+j; break; }    
    }    
}
string str(string s) {return s;}  
void ispis(char *s, int k) {
    for(int i = 0; i < strlen(s); i++) 
      for(int j = 0; j < strlen(niz); j++)
        if(s[i] == niz[j]) {s[i] = niz[s[i]-'a']; break; }
     if(!(k%2))  printf("%s\n", s); 
     else {
         vector<char> a(v[k-1].begin(), v[k-1].end());
         vector<char> b(s, s+strlen(s));
         pair<vector<char>::iterator, vector<char>::iterator> par = 
         mismatch(a.begin(), a.end(), b.begin());
         if(b.begin() != par.second) {
             b.erase(b.begin(), par.second);
             b.insert(b.begin(), par.second-b.begin());
         }
         for(vector<char>::iterator iter = b.begin(); iter != b.end(); iter++) printf("%c", *iter);
         cout << endl;    
         
     }     
}      
int main() {
    int n;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        char temp[52];
        scanf("%s", &temp);
        pretvori(temp);
        v.push_back(str(temp));
    }
    sort(v.begin(), v.end());   
    for(int i = 0; i < v.size(); i++) {
        char temp[52]; strcpy(temp,v[i].c_str()); ispis(temp, i);
    } 
    scanf("\n");
    return 0;
}    
