#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
int main() {
   typedef long int L;
   typedef vector<L>::iterator it;
   long int n, m, a, b, sol = 0;
   vector<L> v;
   scanf("%ld %ld", &n, &m); 
   v.reserve(n);
   for(long int i = 0; i < n; i++) {
       long int t;
       scanf("%ld", &t); v.push_back(t);
   }
   for(long int i = 0; i < m; i++) {
       scanf("%ld %ld", &a, &b);
       pair<it, it> range;
       range.first = lower_bound(v.begin(), v.end(), a);
       range.second = upper_bound(v.begin(), v.end(), b);
       sol+= range.second-range.first;
   }
   printf("%ld", sol);
   scanf("%d", &sol);
   return 0;
}            
