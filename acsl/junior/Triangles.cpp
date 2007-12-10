#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
pair<int, char> a[3], b[3];
int ok() {
  for(int i = 0; i < 3; ++i) 
    if(a[i].first != b[i].first) return 0;
  return 1;
}  
void solve() {
  int gdje;
  for(int i = 0; i < 3; ++i)
    if(a[i].second == 'A') gdje = i;
  for(int i = 0; i < 3; ++i) printf("%c", b[(i+gdje)%3].second);
}  
void input() {
  for(int i = 0; i < 3; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = (i+2)%3 + 'A';
  }  
  for(int i = 0; i < 3; ++i) {
    scanf("%d", &b[i].first);
    b[i].second = (i+2)%3 + 'D';
  }
  sort(a, a+3);
  sort(b, b+3); 
} 
int main() {
  for(int i = 1; i <= 5; ++i) {
    printf("Input #%d: ", i);
    input();
    if(!ok()) printf("Output #%d: NONE", i);
    else {
      printf("Output #%d: ", i);
      solve();
    }
    printf("\n");  
  }
  
  scanf("\n");  
  return 0;
}


