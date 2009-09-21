#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector<int> a[2] = {vector<int>(3), vector<int>(3)};

  for( int i = 0; i < 2; ++i )  {
    for( int j = 0; j < 3; ++j ) 
      scanf("%d", &a[i][j]);
    sort(a[i].begin(), a[i].end());
  }
  
  if( a[0] < a[1] ) swap(a[0], a[1]);
  
  int ok = 1;
  for( int i = 0; i < 3; ++i )
    if( a[0][i] - a[1][i] <= 0 ) 
      ok = 0;
  
  printf("%s\n", ok ? "DA" : "NE");

  return 0;
}
