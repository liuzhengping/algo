#include <cstdio>
#include <cstring>
#include <cctype>

#include <algorithm>
#include <vector>

#define MAXLEN 82

using namespace std;


int main() {
  vector<int> v;
  char buf[MAXLEN];
  while (fgets(buf, MAXLEN, stdin)) {
    v.push_back(strlen(buf) - 1);
  }
  int n = *max_element(v.begin(), v.end());
  int sol = 0;
  for (int i = (int)v.size() - 2; i >= 0; --i)
    sol += (n - v[i]) * (n - v[i]);
  printf("%d\n", sol);
  return 0;
}
