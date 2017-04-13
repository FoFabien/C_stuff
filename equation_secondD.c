#include <stdio.h>
#include <stdlib.h>

long double racine(int n, int x)
{
  if(n == 0)
    return 1;

  return (racine(n - 1, x) + ( x / racine(n - 1, x))) / 2.0;
}

void afficher(long double delta, long double r1, long double r2)
{
  if(delta < 0)
    printf("Aucune racines reelles\n");
  else if(delta == 0)
    printf("Racine double : %16.13Lf\n", r1);
  else
    printf("Racine 1 = %16.13Lf\nRacine 2 = %16.13Lf\n", r1, r2);
}

void equation(long double a, long double b, long double c){

  long double delta = b*b-4*a*c, r1 = 0, r2 = 0;

  if(delta<0);
  else if(delta == 0)
    r1 = -b/(2*a); 
  else
    {
      r1 = (-b + racine(10, delta)) / (2*a);
      r2 = (-b - racine(10, delta)) / (2*a);
    }
  afficher(delta, r1, r2);
}

int main(void){
  long double a=0;
  long double b=0;
  long double c=0;

  printf("entrer la valeur de a :\n");
  scanf("%Lf",&a);
  printf("entrer la valeur de b :\n");
  scanf("%Lf",&b);
  printf("entrer la valeur de c :\n");
  scanf("%Lf",&c);

  equation(a,b,c);
  
  return EXIT_SUCCESS;
}
