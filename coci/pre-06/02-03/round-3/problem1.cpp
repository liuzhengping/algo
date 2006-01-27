#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct d {
    string str;
    int br;
    void broji() {
        for(int i = 0; i < str.size(); i++)
          if(str[i] == 'a' || str[i] == 'A') br++;
    };   
} s[3];   
int main() {
    string str[3];
    for(int i = 0; i < 3; i++) {
        cin >> s[i].str; s[i].broji();
    }
    for(int i = 0; i < 2; i++)
      for(int j = i+1; j < 3; j++) 
          if(s[j].br < s[i].br) {d temp = s[i]; s[i] = s[j]; s[j] = temp;}
    for(int i = 0; i < 3; i++) printf("%s\n", s[i].str.c_str());
    cin >> s[1].str;   
    return 0;
}    
