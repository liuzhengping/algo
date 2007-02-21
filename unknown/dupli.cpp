#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <hash_map.h>
using namespace std;

int main(void) {
    int n, t;
    hash_map<int, bool> s;
    vector<int> v;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", &t); 
      if(!s.count(t)) {s[t] = true; v.push_back(t); } 
    }
    for(int i = 0; i < v.size(); i++) printf("%d\n", v[i]); 
   /* int n;
    vector<int> v;
    scanf("%d", &n);
    v.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i = 0; i < v.size(); i++) printf("%d\n", v[i]); */
    scanf("\n");
    return 0;
}
