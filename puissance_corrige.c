#include <stdio.h>
#include <stdlib.h>

int puissance(int x, int n)
{
  int resultat = 1, i;

  for(i = 0; i <= n; i++)
    resultat *= x;
  return resultat;
}

void affiche(int a, int b)
{
  printf("%d^%d = %d\n", a, b, puissance(a, b));
}

int main(int nbArgs, char* args[])
{
  int x, n;

  if(nbArgs == 3)
    affiche(atoi(args[1]), atoi(args[2]));

  /*-----------------------*/

  affiche(2, 10);

  /*-----------------------*/

  printf("donne 2 entiers\n");
  scanf("%d %d", &x, &n);
  affiche(x, n);

  return EXIT_SUCCESS;
}
