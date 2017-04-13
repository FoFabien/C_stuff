#include <stdio.h>
#include <stdlib.h>

void afficher(int i, int x){
  int a = 0;

  for(a = 1; a <= x; a++)
    {
    if(i*a >= 100)
      printf("%d ", i*a);
    else if(i*a >= 10)
      printf("%d  ", i*a);
    else
      printf("%d   ", i*a);
    }
    printf("\n");
  
}

void multiplication(int x){

  int i=0;
  for(i=1;i<=x;i++)
    afficher(i, x);
}

int main()
{
  int x = 0;

  printf("Donnez un nombre\n");
  scanf("%d", &x);

  multiplication(x);

  return EXIT_SUCCESS;
}
