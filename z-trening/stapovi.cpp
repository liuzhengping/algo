#include <cstdio>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <iostream>
#define sgn(x) ((x < 0) ? -1 : 1)
using namespace std;
int n, m;
struct kruznica {
  double p, q, r;
};
int intersects(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
  //da li se "duzina" 12 sijece s 34
  double maxd = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
  maxd >?= (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);
  maxd >?= (x1-x4)*(x1-x4) + (y1-y4)*(y1-y4);
  maxd >?= (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3);
  maxd >?= (x2-x4)*(x2-x4) + (y2-y4)*(y2-y4);
  maxd >?= (x3-x4)*(x3-x4) + (y3-y4)*(y3-y4);
  return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ) + sqrt( (x3-x4)*(x3-x4) + (y3-y4)*(y3-y4) )
         >= sqrt( maxd );
}  
struct stap {
  double x1, x2, y1, y2;
  double px, py; //poloviste stapa
  int ok1, ok2; //da li neki kraj stapa ne moze pasti?
  void update(kruznica a) {
    stap curr = *this;
    //translatiraj cijeli sustav
    curr.x1 -= a.p; curr.x2 -= a.p;
    curr.y1 -= a.q; curr.y2 -= a.q;
    //sad izracunaj sjecista pomocu formule
    double dx = curr.x2 - curr.x1, dy = curr.y2 - curr.y1;
    double sq_dr = dx*dx+dy*dy;
    double D = curr.x1*curr.y2 - curr.x2*curr.y1;
    double disc = a.r*a.r*sq_dr-D*D;
    if(disc < 0)
      return ; //nema sjecista
      
    disc = sqrt(disc);
    //koordinate sjecista prije translacije
    double xx1 = ( D*dy + sgn(dy)*dx*disc )/sq_dr;
    double xx2 = ( D*dy - sgn(dy)*dx*disc )/sq_dr;
    double yy1 = (-D*dx + abs(dy)*disc    )/sq_dr;
    double yy2 = (-D*dx - abs(dy)*disc    )/sq_dr;
    //translatiraj cijeli sustav natrag
    xx1 += a.p;  xx2 += a.p;
    yy1 += a.q;  yy2 += a.q;
    //gledam koji su krajevi stabilni
    if( intersects( xx1, yy1, xx2, yy2, x1, y1, px, py ) ) ok1 = 1;
    if( intersects( xx1, yy1, xx2, yy2, x2, y2, px, py ) ) ok2 = 1;
  }  
  stap() {}
  stap(double x1, double y1, double x2, double y2) {
    this->x1=x1; this->y1=y1; this->x2=x2; this->y2=y2;
    px = (x1+x2)/2; py = (y1+y2)/2;
    ok1 = ok2 = 0;
  }    
};  
vector<kruznica> k;  
vector<stap> s;
int main() {
  scanf("%d", &n); k.resize(n);
  for(int i = 0; i < n; ++i) 
    scanf("%lf%lf%lf", &k[i].p, &k[i].q, &k[i].r);
  scanf("%d", &m); s.resize(m);
  for(int i = 0; i < m; ++i) {
    double x1, y1, x2, y2;
    scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
    s[i] = stap(x1, y1, x2, y2);
  }  
  for(int i = 0; i < m; ++i) {
    for(int j = 0; j < n; ++j)
      s[i].update(k[j]);  
    if(s[i].ok1 && s[i].ok2) printf("DA\n");
    else printf("NE\n");
  }    
  return 0;
}


