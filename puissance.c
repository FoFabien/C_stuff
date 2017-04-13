#include <stdio.h>
#include <stdlib.h>


int Puissance(int x, int n)
{
  int r = 1;

  while(n > 0)
    {
      if(n % 2 == 1)
	  r = r * x;
      x = x * x;
      n = n / 2;
    }
  return r;
}


int main()
{
  int x = 0, n = 0;

  printf("Entrer un entier\n");
  scanf("%d", &x);

  printf("Entrer la puissance\n");
  scanf("%d", &n);

  printf("Le resultat est %d\n", Puissance(x,n));

  return 0;

}
