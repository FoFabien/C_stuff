#include <stdio.h>
#include <stdlib.h>

void afficher(int n, int r)
{
  printf("Le terme %d de la suite de Fibonacci est %d\n", n, r);
}

int fibonacci_iteratif(int n)
{
  int i = 0, r = 1, a = 1, b = 0;

  if(n == 0)
    return 0;
  else if(n == 1)
    return 1;

  for(i = 2; i <= n; i++)
    {
      //tmp = r;
      r = a + b;
      b = a;
      a = r;
    }

  return r;
}

int fibonacci_recursif(int n)
{

  if(n == 0)
    return 0;
  else if(n == 1)
    return 1;

  return fibonacci_recursif(n - 1) + fibonacci_recursif(n - 2);
}

int main()
{
  int n = 0;

  printf("Entrez le terme de la suite de Fibonacci\n");
  scanf("%d", &n);

  afficher(n, fibonacci_iteratif(n));
  afficher(n, fibonacci_recursif(n));

  return EXIT_SUCCESS;
}
