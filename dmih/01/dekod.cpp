#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <deque>
#define MAX 103
using namespace std;
int k, kk; char rijec[MAX], input[MAX];
int main() {
    scanf("%s", &rijec);
    scanf("%d", &kk);
    scanf("%s", &input);
    char niz[27], niz2[27]; 
    vector<char> v; k = 1; deque<char> d;
    for(char c = 'a'; c <= 'z'; ++c) v.push_back(c); 
    for(int i = 0; i < 26; ++i) niz[i] = 'a'+i;
    for(int i = 0; i < strlen(rijec); ++i) v.erase(remove(v.begin(), v.end(), rijec[i]));
    for(int i = 0; i < strlen(rijec); ++i) niz2[k-1+i] = rijec[i];
    for(int i = 0; i < v.size()-(k-1); ++i) niz2[k-1+strlen(rijec)+i] = v[i];
    for(int i = k-2, j = v.size()-1; i >= 0; --i, --j) niz2[i] = v[j];
    for(int i = 0; i < 26; ++i) d.push_back(niz2[i]);
    for(int i = 0; i < kk-k; ++i) {d.push_front(d.back()); d.pop_back(); }
    for(int i = 0; i < 26; ++i) niz2[i] = d[i];
    niz2[26] = '\0';
    for(int i = 0; i < strlen(input); ++i) {
        for(int j = 0; j < 26; ++j) 
          if(niz2[j] == input[i])  {
              input[i] = j+'a';
              break;
          }    
    }    
    printf("%s", input); 
    scanf("\n");
    return 0;
}    
