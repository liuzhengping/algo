#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream.h>
#include <functional>
#include <ctype.h>
#include <cmath>
#include <vector.h>
#include <algorithm>
using namespace std;
int val[100], V = 4, id = -1; int umn; char broj[10];
vector<int> v1;
void write() {
    char f1[10], f2[10]; int i, br1 = 0, br2 = 0;
    for(i = 0; i < V/2; i++) 
       f1[i] = broj[ val[i+1] -1];
    f1[i] = '\0';
    br1 = atoi(f1);
    int k = 0;
    for(i = V/2; i < V; i++) 
       f2[k++] = broj[ val[i+1] -1];
    f2[i] = '\0';
    br2 = atoi(f2);
    if(br1*br2 == umn && (br1%100 != 0) && (br2%100 != 0)) {
      bool da1 = binary_search(v1.begin(), v1.end(), br1);
      if(da1) goto van;
      da1 = binary_search(v1.begin(), v1.end(), br2);
      if(da1) goto van;
      printf("\n%d,%d", br1, br2);
      v1.push_back(br1); v1.push_back(br2);
      sort(v1.begin(), v1.end());
    }
    van:
    bool bezveze;
            
    
    
}       
void visit(int k) {
    int t;
    val[k] = ++id;
    if(id == V) write();
    for(t = 1; t <= V; t++) 
        if (val[t] == 0) visit(t);
    id--; val[k] = 0;
}
int main() {
    scanf("%d", &umn);
    sprintf(broj, "%d", umn);
    V = strlen(broj);
    visit(0);
    getch();
    return 0;
}
