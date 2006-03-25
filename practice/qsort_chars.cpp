#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
void qs(string *a, int l, int r) {
    int j, i;
    string v, t;
    if(r > l) {
        v = a[r]; i = l-1; j = r;
        for(;;) {
            while(a[++i] <  v);
            while(a[--j] > v);
            if(i >= j) break;
            t = a[i]; a[i] = a[j]; a[j] = t;
        }
        t = a[i]; a[i] = a[r]; a[r] = t;
        qs(a, l, i-1);
        qs(a, i+1, r);
    }
}            
int main() {
    string s[100];
    int k = 0;
    for(string str; cin >> str, str != "0"; s[k++] = str) ;
    qs(s, 0, k-1);
    for(int i = 0; i < k; i++) cout << s[i] << endl;
    cin >> s[0];
    return 0; 
}    
