#include <cstdio>
#define MAX 100002
using namespace std;
int n, a[MAX];
void input() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
}
void output(int sol) {
  printf("%d", sol);
}  
int solve() {
  int curr = 1;
  for(int x = a[0]-1; curr < n; ++curr, --x) {
    if(!x) return curr;
    x >?= a[curr];
  }
  return curr;
}    
int main() {
  input();
  output(solve());
  //scanf("\n");
  return 0;
}  
