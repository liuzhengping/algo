#include <cmath>
#include <cstdio>
#include <cstring>
#include <cctype>

#include <algorithm>
#include <limits>
#include <utility>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

bool solve() {
  int n;
  if (scanf("%d", &n) != 1)
    return false;

  for (int i = 0; i < n; ++i)
    scanf("%d", &n);
  vector<int> a(n);
  sort(a.begin(), a.end());

  for (int i = n - 1; i >= 0; --i) {
    for (int j = i - 1; j >= 0; --j) {
      if (gcd(a[i], a[j]) == 1) {
	printf("%d\n", a[i]);
	return true;
      }
    }
    printf("?\n");
    return true;
  }
}

int main() {
  while (solve()) ;
  
  return 0;
}
