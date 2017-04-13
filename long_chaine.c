#include <stdio.h>
#include <stdlib.h>

int longueur(char chaine[])
{
  int n = 0;

  while(chaine[n] != '\0')
    {
      n++;
    }
  return n;
}

int main(void)
{
  char chaine[50];

  printf("Entrez une chaine de caracteres\n");
  scanf("%s", chaine);

  printf("taille : %d\n", longueur(chaine));

  return EXIT_SUCCESS;
}
