#include <stdio.h>
int main (void)
{
  long long a, b, c, y;
  scanf("%Li %Li %Li", &a, &b, &c);
  if (a == b || a == c )
        y = a;
  else if (b == c)
        y = b;
  else if ((a < b && a > c) || (a > b && a < c))
        y = a;
  else if ((b < a && b > c) || (b > a & b < c))
        y = b;
  else if ((c < b && c > a) || (c > b && c < a))
        y = c;
  printf ("%Li\n", y);
  while (getchar() != 'q')  ;
  return 0;
}

