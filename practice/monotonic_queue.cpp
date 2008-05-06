#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <iostream>
#define MAX 10005
using namespace std;
struct myq {
  queue<int> q;
  deque<int> dmin, dmax;
  void push(int x) {
    for(; !dmin.empty() && dmin.back() > x; dmin.pop_back()) ;
    for(; !dmax.empty() && dmax.back() < x; dmax.pop_back()) ;
    dmin.push_back(x);
    dmax.push_back(x);
    q.push(x);
  }
  void pop() {
    if(dmin.front() == q.front()) dmin.pop_front();
    if(dmax.front() == q.front()) dmax.pop_front();
    q.pop();
  }
  void print() {
    printf("%d %d: ", (dmin.size()) ? dmin.front(): -1, (dmax.size()) ? dmax.front(): -1);
    queue<int> t(q);
    for(; !t.empty(); t.pop())
      printf("%d ", t.front());
    printf("\n");
    for(int i = 0; i < dmin.size(); ++i) printf("(%d)", dmin[i]);
    printf("\n");
  }
} moj;
void gen() {
  srand( time(0));
  for(int i = 0; i < 1000000; ++i) {
    if(moj.q.size() && rand()%2) moj.pop();
    else moj.push(rand()%252);
    //if(rand()%2 && moj.q.size() > 1) moj.pop();
    //else moj.push(rand()%236); 
  }  
}  
int main(void) {
  //gen();
  //printf("gotovo");
  for(int x = 1; x; ) {
    scanf("%d", &x);
    if(x < 0) moj.pop();
    else moj.push(x);
    moj.print();
  }
  return 0;
}
