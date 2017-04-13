#include <stdio.h>
#include <stdlib.h>

int copie(int T1[], int T2[], int taille)
{
  int n = 0, i = 0;

  for(n = 0; n < taille; n++)
    {
      if(T2[n] >= 0)
	{
	  T1[n] = T2[n];
	  i++;
	}
    }  

  return i;
}

int main(void)
{
  int T1[10];
  int T2[10] = {-1, 4, -5, 3, 2, 1, 0, 8, -10, -2};
  int taille = 10;

  printf("nombre d'element copier : %d\n", copie(T1, T2, taille));

  return EXIT_SUCCESS;
}
