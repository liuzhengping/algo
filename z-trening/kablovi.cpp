#include <cstdio>
#include <queue>
#include <iostream>
#include <vector>
#include <cmath>
#define MAX 102
using namespace std;
int n;
struct point {
    int x, y;
    point() {x=0;y=0;}
    point(const int& x, const int& y) {this->x = x; this->y = y;}
};
double sq(const double& a) {return a*a;}  
vector< point > t;
double dist[MAX][MAX]; int intree[MAX];
struct comp {
    bool operator()(const pair<double, int>& a, const pair<double, int>& b) {
        return a.first > b.first;
    }    
} ;   
int main() {
    scanf("%d", &n);
    t.resize(n);
    for(int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        t[i] = point(a, b); 
    }
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
          dist[i][j] = sqrt(sq(double(t[i].y-t[j].y))+sq(double(t[i].x-t[j].x)));
    double sol = 0;
    priority_queue<pair<double, int>, vector< pair<double, int> >, comp > pq;
    for(int i = 0; i < n; ++i) {
        if(i) pq.push(make_pair(dist[0][i], i));
    }
    intree[0] = 1;   
    for(;!pq.empty();) {
        pair<double, int> par = pq.top(); pq.pop();
        if(intree[par.second]) continue;
        sol += par.first;
        //printf("(%d)", par.second); cin.get();
        intree[par.second] = 1; int bio = 0;
        for(int i = 0; i < n; ++i) { 
          if(!intree[i]) {
              bio = 1;
              pq.push(make_pair(dist[par.second][i], i)); 
          }
        }
        if(!bio) break;                
    }
    printf("%.2lf", sol);       
    scanf("\n");
    return 0;
}   
