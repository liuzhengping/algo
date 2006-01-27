#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char zn[7] = {'I','V','X','L','C','D','M'};
int vr[7] = {1,5,10,50,100,500,1000};
int main() {
    string str; int sol = 0;
    cin >> str;
    reverse(str.begin(), str.end());
    for(int i = 0; i < str.size(); i++) {
        char t_zn; int t_vr, vr2;
        for(int j = 0; j < 7; j++)
          if(zn[j] == str[i]) {t_zn = zn[j]; t_vr = vr[j];}
        if(i == 0) {sol+= t_vr; continue;}
        for(int j = 0; j < 7; j++)
          if(zn[j] == str[i-1]) vr2 = vr[j];
        if(vr2 <= t_vr) sol+=t_vr;
        else sol-=t_vr;
    }
    printf("%d", sol);
    cin >> str;    
    return 0;
}    
