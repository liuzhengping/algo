#include <cstdio>
#include <cstdlib>
using namespace std;
int main() {
  for(int i=0;i<5;i++) {
    float a,b,c,d,e,f;
    scanf("%f %f %f %f %f %f",&c,&a,&b,&f,&d,&e);
    if(c==f && a==d && b==e) printf("DEF");
    else if(c==f && a==e && b==d) printf("EDF");
    else if(c==e && a==d && b==f) printf("DFE");
    else if(c==e && a==f && b==d) printf("FDE");
    else if(c==d && a==e && b==f) printf("EFD");
    else if(c==d && a==f && b==e) printf("FED");
    else printf("none");
    printf("\n");
  }
  return 0;
}
