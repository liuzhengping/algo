#include <cstdio>
#include <algorithm>
#define MAX 30005
#define MOD 10007
using namespace std;
int a[MAX], n, sol;
void solve() {
  sort(a, a+n);
  int comb = 1;
  for(int i = 2; i < n; ++i) {
    sol = (sol + (long long) a[i] * comb + (long long) MOD*(100207))%MOD;
    comb = (comb+i)%MOD;
  }
  printf("%d\n", sol);
}
void input() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
}
int main() {
  input();
  solve();
  return 0;
}