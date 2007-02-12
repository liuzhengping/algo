#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
vector<string> niz; int n = 0;
typedef vector<string>::iterator vsi;
int num(const string s) { return atoi(s.c_str()); }    
int rek(int curr) {
    if(niz[curr][0] >= '0' && niz[curr][0] <= '9') {
        int ret = num(niz[curr]);
        niz.erase(niz.begin()+curr);
        return ret;
    }
    string znak = niz[curr];
    niz.erase(niz.begin()+curr);
    if(znak == "+") return rek(curr) + rek(curr);
    else if(znak == "-") return rek(curr) - rek(curr);
    else if(znak == "*") return rek(curr) * rek(curr);
    else if(znak == "/") return rek(curr) / rek(curr);
    else if(znak == "%") return rek(curr) % rek(curr);
    else if(znak == "<?") return rek(curr) <? rek(curr);
    else if(znak == ">?") return rek(curr) >? rek(curr);
    else if(znak == "sqrt") return int(sqrt(double(rek(curr))));
}    
int main() {
    char *podniz, input[1000];
    gets(input);
    podniz = strtok(input, " ");
    do {
        niz.push_back(string(podniz));
        podniz = strtok(NULL, " ");
    } while(podniz);
    printf("%d", rek(0));
    scanf("\n");
    return 0;
}   
// + - * / 4 2 + 2 3 5 3
