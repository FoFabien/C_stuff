/*----------------------------------------------------------------------------------------------
 * Note : Envoyer le fichier "poemes.txt" en argument (chemin absolu ou relatif)
 * -------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void afficher(char chaine[])
{
  printf("\t%s", chaine);
}

void aleatoire(char poeme[14][10][100])
{
  unsigned int i = 0;

  printf("\n\n");

  for(i = 0; i < 14; i++)
    {
      if((i == 4) || (i == 8) || (i == 11))
	afficher("\n");
      afficher(poeme[i][(rand()%10)]);
    }

  printf("\n\n");
}

void lecture(char poeme[14][10][100], char* args[])
{
  FILE *fichier = NULL; // pointeur vers le fichier
  char chaine[100];

  int i = 0, j = 0; // i => page, j => ligne

  fichier = fopen(args[1], "r"); // ouverture en lecture seule

  if(fichier != NULL) // verification d'ouverture
  {
    for(i = 0; i < 14; i++)
      {
	for(j = 0; j < 10; j++)
	  {
	    fgets(poeme[i][j], 100, fichier); // on stock les vers de chaque poemes
	  }
	fgets(chaine, 100, fichier); // on fait un fgets pour la ligne vide entre chaque poemes
      }
  }
  else
    fprintf(stderr, "\nErreur : Ouverture du fichier impossible\nAvez vous indiquer le bon chemin ?\n"); // erreur si l'ouverture du fichier est impossible
      
fclose(fichier); // on ferme le fichier
}

int main(int nbArgs, char* args[]) // on récupère le chemin du .txt en argument. (Note : ~bienvenu/Public/E1/poemes.txt)
{
  srand(time(NULL));
  char poeme[14][10][100]; // 14 pages, 10 lignes par pages, 100 caracteres par lignes

  if(nbArgs > 1)
    {
      lecture(poeme, args);
      aleatoire(poeme);
    }
  else
    fprintf(stderr, "\nErreur : Veuillez indiquer le fichier a ouvrir en parametre\n");

  return EXIT_SUCCESS;
}
