#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NB_LIGNES 14
#define NB_CHOIX 10
#define MAX 100

void chargerPoemes(char poemes[][NB_CHOIX][MAX])
{
  int i, j;
  char bidon[10];

  for(i = 0; i < NB_LIGNES; i++)
    {
      for(j = 0; j < NB_CHOIX; j++)
	fgets(poemes[i][j], MAX, stdin);
      fgets(bidon, MAX, stdin);
    }
}

void afficherPoemes(char poemes[][NB_CHOIX][MAX])
{
  int i;
  printf("\n");
  for(i = 0; i < NB_LIGNES; i++)
    {
      printf("\t%s", poemes[i][rand()%NB_CHOIX]);
      if(i == 3 || i == 7 || i == 10)
	printf("\n");
    }
  printf("\n\n");
}

int main()
{
  char poemes[NB_LIGNES][NB_CHOIX][MAX];
  srand(time(NULL));

  chargerPoemes(poemes);
  afficherPoemes(poemes);

  return EXIT_SUCCESS;
}
