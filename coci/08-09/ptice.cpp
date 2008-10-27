#include <cstdio>
#include <iostream>
using namespace std;
char a[] = "ABC", b[] = "BABC", c[] = "CCAABB", s[105];
char ime[3][10] = {"Adrian", "Bruno", "Goran"};
int n, la, lb, lc;
pair<int, int> niz[3] = {make_pair(0,0), make_pair(0,-1), make_pair(0,-2)};
int main() {
  la = strlen(a); lb = strlen(b); lc = strlen(c);
  scanf("%d%s", &n, &s);
  for(int i = 0; i < n; ++i) {
    if(a[i%la] == s[i]) ++niz[0].first;
    if(b[i%lb] == s[i]) ++niz[1].first;
    if(c[i%lc] == s[i]) ++niz[2].first;
  }
  sort(niz, niz+3, greater<pair<int, int> >());
  int k;
  for(k = 1; k < 3 && niz[k].first == niz[k-1].first; ++k) ;
  printf("%d\n", niz[0].first);
  for(int i = 0; i < k; ++i)
    printf("%s\n", ime[ -niz[i].second ]);
  return 0;
}
