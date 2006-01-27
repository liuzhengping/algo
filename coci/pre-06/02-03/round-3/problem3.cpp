#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector.h>
#include <algorithm>
using namespace std;
int main() {
    char *podniz, str[100], c;
    int k = 0;
    vector<string> s;
    while((c = cin.get()) != '\n') 
    str[k++] = c;
    str[k] = '\0';
    podniz = strtok(str, " ");
    if(podniz) {
        do {
            s.push_back(podniz);
            podniz = strtok(NULL, " ");
        } while(podniz);
    }
    reverse(s.begin(), s.end());
    for(vector<string>::iterator it = s.begin(); it != s.end(); it++)
      cout << *it << " ";
    cin >> k;        
    return 0;
}    
