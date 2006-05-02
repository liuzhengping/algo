#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;
int vece[MAX], manje[MAX];
int n, d;
vector<pair<int, int> > v;
int main() {
    scanf("%d %d", &d, &n);
    for(int i = 0; i < n; i++) {
      int a, b; scanf("%d %d", &a, &b);
      v.push_back(make_pair<int, int>(a, b));
    }
    for(int i = 0; i <= d; i++) {vece[i] = 0; manje[i] = 0;}
    for(int j = 0; j < n; j++) {
      for(int i = 0; i <= d; i++) {
          if(i >= v[j].first) {
              if(vece[i-v[j].first]+v[j].second > vece[i] && (!(i-v[j].first) || vece[i-v[j].first]))
                vece[i] = vece[i-v[j].first]+v[j].second;
              if(manje[i-v[j].first] + v[j].second < manje[i] || !manje[i])
                manje[i] = manje[i-v[j].first]+v[j].second;
          }    
      }
    }
    printf("%d\n%d", manje[d], vece[d]);           
    scanf("\n");
    return 0;
}    
