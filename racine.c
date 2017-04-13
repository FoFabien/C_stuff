#include <stdio.h>
#include <stdlib.h>

long double racine(int n, int x)
{
  if(n == 0)
    return 1;
  return (racine(n - 1, x) + ( x / racine(n - 1, x))) / 2.0;
}
