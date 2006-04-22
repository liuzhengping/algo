#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n , k;
    vector<pair <int, int> > v;
    scanf("%d %d", &n, &k);
    v.reserve(k);
    for(int i = 0; i < k; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v.push_back( make_pair <int, int> (b, a));
    }
    bool da = true;
    sort(v.begin(), v.end(), greater<pair<int, int> >());
    for(int i = 0; i < k; i++) {
        if(v[i].first >= n) {da = false; break;}
        n-=v[i].first-v[i].second+1;
    }
    if(da) 
        for(vector<pair <int, int> >::iterator iter = v.begin(); iter != v.end(); iter++)
          printf("%d %d\n", (*iter).second, (*iter).first);
    else printf("-1");        
    scanf("\n");
    return 0;
}    
