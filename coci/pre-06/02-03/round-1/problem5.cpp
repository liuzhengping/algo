#include <vector.h>
#include <algorithm>
#include <cstdio>
#include <iostream.h>
using namespace std;
typedef long long int LL;
int main() {
    int n; LL suma;
    vector<LL> v;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int t; scanf("%d", &t); v.push_back(t);
    }
    for(;;) {
        sort(v.begin(), v.end());
        vector<LL> v1;
        if(v.size() <= 1) break;
        if(v.size()%2) v1.push_back(v[v.size()-1]); 
        for(int i = 0; i < (v.size() - v.size() % 2); i+=2) {
            v1.push_back(v[i]+v[i+1]); suma+=(v[i]+v[i+1]);
        }
        v.clear(); v.resize(v1.size());
        copy(v1.begin(), v1.end(), v.begin());
    }        
        
    printf("%d", suma);    
    int tmp; scanf("%d", &tmp);
    return 0;
}    
