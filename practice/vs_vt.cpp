#include <cstdio>
#include <cmath>
double v_of_s(double s) {
  return 1 + log(1+s);
}
void stat() {
  double dt = 1e-5, final_t = 100, s = 0;
  double interval = 1e0, last_t = 0;
  for( double t = 0; t < final_t; t += dt ) {
    s += dt * v_of_s(s);
    if( t-last_t >= interval ) {
      last_t = t;
      printf("t = %lf\ts=%lf\n", t, s);
    } 
  }
  printf("t = %lf\ts=%lf\n", final_t, s);
}
int main() {
  stat();
  return 0;
}
