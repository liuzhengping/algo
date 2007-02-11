#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 105
char p[MAX][MAX];
int r, s;
struct prozor {
    int w, h;
    string ime;
} ;
struct mojsort {
    bool operator()(const prozor& a, const prozor& b) {return a.ime < b.ime;}
} ;    
vector<prozor> v;  
void print() {
    for(int i = 0; i < r; ++i) printf("%s\n", p[i]);
}     
int main() {
    scanf("%d %d", &r, &s);
    for(int i = 0; i < r; ++i) scanf("%s", &p[i]);
    for(int i = 0; i < r; ++i) 
      for(int j = 0; j < s; ++j) {
          if(p[i][j] == '+') {
              int w, h; prozor novi;
              p[i][j] = '.';
              for(w = 1; ; ++w) {
                if(p[i][j+w] == '+') {p[i][j+w] = '.'; novi.w = w+1; break;} 
                if(p[i][j+w] >= 'a' && p[i][j+w] <= 'z') novi.ime.push_back(p[i][j+w]);
                p[i][j+w] = '.';
              }
              for(h = 1; ; ++h) {
                if(p[i+h][j+w] == '+') {p[i+h][j] = '.'; novi.h = h+1; break; }
                p[i+h][j+w] = p[i+h][j] = '.';  
              } 
              for(w = 1; ; ++w) {
                if(p[i+h][j+w] == '+') {p[i+h][j+w] = '.';  break;} 
                p[i+h][j+w] = '.';
              }
              v.push_back(novi);    
          }    
      }
    sort(v.begin(), v.end(), mojsort); 
    for(int k = 0; k < v.size(); ++k) {
        for(int w = 1; w < v[k].w; ++w) p[k][k+w] = p[k+v[k].h-1][k+w] = '-';
        for(int h = 1; h < v[k].h; ++h) p[k+h][k] = p[k+h][k+v[k].w-1] = '|';
        for(int i = 1; i < v[k].w-1; ++i)
          for(int j = 1; j < v[k].h-1; ++j) p[k+j][k+i] = '.';
        p[k][k] = p[k][k+v[k].w-1] = p[k+v[k].h-1][k] = p[k+v[k].h-1][k+v[k].w-1] = '+'; 
        int br = (v[k].w-4-v[k].ime.size())/2;
        int gdje = k+br+2; p[k][gdje-1] = p[k][gdje+v[k].ime.size()] = '|';
        for(int i = 0; i < v[k].ime.size(); ++i) p[k][gdje+i] = v[k].ime[i];
    }
    print();       
    scanf("\n");
    return 0;
}    
