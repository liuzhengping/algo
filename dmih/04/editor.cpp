#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;
int main() {
    char tmp[100001]; int n;
    string s;
    //cin >> s;
    list<char>::iterator it, iter;
    scanf("%s", &tmp);
    list<char> l(tmp, tmp+strlen(tmp));
    it = l.end();
    scanf("%d", &n);
    cin.get();
    size_t ind;
    for(int i = 0; i < n; i++) {
        char str[5], c; int k = 0;
        while((c = cin.get()) != '\n') str[k++] = c;
        //scanf("%s", &str);
        /*if(str[0] == 'L' && ind) ind--; 
        else if(str[0] == 'D' && ind != s.size()) ind++;
        else if(str[0] == 'B' && s.size() && ind) s.erase(--ind);
        else if(str[0] == 'P') s.insert(s.begin()+ind, str[2]);*/
        if(str[0] == 'L' && it != l.begin()) it--; 
        else if(str[0] == 'D' && it != l.end()) it++;
        else if(str[0] == 'B' && l.size() && it != l.begin()) {
            iter = it--;
            l.erase(it);
            it = iter;
        }    
        else if(str[0] == 'P') l.insert(it, str[2]);
        /*printf("(%c)", *it);
         for(iter = l.begin(); iter != l.end(); iter++) printf("%c", *iter);   
         cout << endl;*/
        
    }
    for(it = l.begin(); it != l.end(); it++) printf("%c", *it);   
    //cout << s; 
    scanf("\n");
    return 0;
}
/*
umivalo
automobil
*/    
