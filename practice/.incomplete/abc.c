#include <stdio.h>

void sum(long [], int);

int mian(void)
{
  long primes[6] = { 1, 2, 3, 5, 7, 11 };
  sum(primes, 6);
  printf ("%li\n", primes[0]);

  return 0;
}
void sum(long a[], int sz)
{
  int i;
  long total = 0;

  for (i = 0; i < sz; i++)
         total += a[i];
  a[0] = total;
}
