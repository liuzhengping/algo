#include <stdio.h>
#include <conio.h>
#include <math.h>
int main() {
    double dist;
    int p, q, r, P, Q, R;
    for(int puta = 1; puta <= 5; puta++) {
      printf("Line #%d: ", puta);
      scanf("%d %d %d %d %d %d", &p, &q, &r, &P, &Q, &R);
      dist = sqrt( pow(p-P, 2) + pow(q-Q, 2) );
      printf("Output #%d: ", puta);
      if(dist > r + R) printf("non-intersecting\n");
      else if(dist == r + R) printf("externally tangent\n");
      else {
          if(r > R) {
              int t = r;
              r = R;
              R = t;
          }
          if(dist < r + R && dist > R - r) printf("intersecting\n");
          else if(dist == R - r) printf("internally tangent\n");
          else if(dist < R - r) printf("nested\n");
      }        
    }    
    getch();
    return 0;
}    
