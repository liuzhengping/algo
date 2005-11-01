#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <iostream.h>
#include <algorithm>
#include <vector.h>
#include <list.h>
#include <functional>
using namespace std;
int susj[6][2];
int smjer = 0;
double start;
list<string> v;
list<string>::iterator iter;
long int counter = 1;
string str(string s) {
  return s;
}
void init() {
    susj[0][0] = -1; susj[0][1] = 0;
    susj[1][0] = 0; susj[1][1] = -1;  
    susj[2][0] = 1; susj[2][1] = -1;  
    susj[3][0] = 1; susj[3][1] = 0;  
    susj[4][0] = 0; susj[4][1] = 1;  
    susj[5][0] = -1; susj[5][1] = 1;
}
int inc(int smj) {
    if(smj == 5) return 0;
    else return smj+1;
}  
int dec(int smj) {
    if(smj == 0) return 5;
    else return smj-1;
}           
void visit(int x, int y, int sm, long int sol) {
    string t;
    char temp[9], temp2[9];
    sprintf(temp, "%d", x); sprintf(temp2, "%d", y);
    strcat(temp, " ");
    strcat(temp, temp2);
    t = str(temp);
    
    iter = find(v.begin(), v.end(), t);
    if(iter == v.end()) {
        if(++counter == sol) {
          printf("(%d,%d)", x, y);
          printf("\n%lf ms", clock()-start);    
          getch();
          exit(0);
        }    
        v.push_back(t);
        visit(x+susj[inc(sm)][0], y+susj[inc(sm)][1], inc(sm), sol);
        visit(x+susj[sm][0], y+susj[sm][1], sm, sol);
    }
    else 
        v.erase(iter);    
    
}              
int main() {
    int x, y, x2, y2;
    long int rez;

    v.push_back("0 0");
    x = 0; y = 1;
    init();
    scanf("%ld", &rez);
    start = clock();
    visit(0, 1, 0, rez);
    return 0;
}    
