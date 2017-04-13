/*-----------------------------------------------------------------------------------------------------------------------------------
 * Auteur : Forest Fabien - E1
 * Poemes.c
 *
 * Note : Envoyer le fichier "poemes.txt" en argument (chemin absolu ou relatif)
 *
 ----------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <time.h>

void affichage(char ver1[100], char ver2[100], char ver3[100], char ver4[100], int x)
{
	switch(x)
	{
	case 1:
	  printf("%s", ver1);
	  printf("%s", ver2);
	  printf("%s", ver3);
	  printf("%s", ver4);
	  break;
	case 2:
	  printf("%s", ver1);
	  printf("%s", ver2);
	  printf("%s", ver3);
	  break;
	}
}

void random_page(unsigned int page[])
{
  unsigned int i = 0;
  //srand(time(NULL));

  for(i = 0; i < 5; i=i+2) // On choisi les pages (on evites d'avoir les 2 memes rimes pour un quatrain ou un tercet) et on considere que les deux tercets auront les memes rimes
    {
      page[i] = rand()%14;
      do{
	page[i+1] = rand()%14;
      }while(page[i+1] == page[i]);
    }
}

void ver_quatrain(unsigned int ver[], unsigned int progression)
{
  //srand(time(NULL));
  ver[progression] = rand()%10;
  do{
    ver[progression+1] = rand()%10;
  }while(ver[progression+1] == ver[progression]);
  
  do{
    ver[progression+2] = rand()%10;
  }while((ver[progression+2] == ver[progression+1]) || (ver[progression+2] == ver[progression]));
  
  do{
    ver[progression+3] = rand()%10;
  }while((ver[progression+3] == ver[progression+2]) || (ver[progression+3] == ver[progression+1]) || (ver[progression+3] == ver[progression]));

}

void ver_tercet(unsigned int ver[], unsigned int progression)
{
  //srand(time(NULL));
  ver[progression] = rand()%10;

  do{
    ver[progression+1] = rand()%10;
  }while(ver[progression+1] == ver[progression]);

  do{
    ver[progression+2] = rand()%10;
  }while((ver[progression+2] == ver[progression+1]) || (ver[progression+2] == ver[progression]));

}

void rand_affichage(char poeme[14][10][100], unsigned int page[], unsigned int ver[], unsigned int progression, unsigned int random, unsigned int quatrain)
{
  switch(random)
    {
    case 0:
      affichage(poeme[page[quatrain*2-2]][ver[progression-4]],
		poeme[page[quatrain*2-2]][ver[progression-3]],
		poeme[page[quatrain*2-1]][ver[progression-2]],
		poeme[page[quatrain*2-1]][ver[progression-1]], 1);
      break;
    case 1:
      affichage(poeme[page[quatrain*2-2]][ver[progression-4]],
		poeme[page[quatrain*2-1]][ver[progression-3]],
		poeme[page[quatrain*2-1]][ver[progression-2]],
		poeme[page[quatrain*2-2]][ver[progression-1]], 1);
      break;
    case 2:
      affichage(poeme[page[quatrain*2-2]][ver[progression-4]],
		poeme[page[quatrain*2-1]][ver[progression-3]],
		poeme[page[quatrain*2-2]][ver[progression-2]],
		poeme[page[quatrain*2-1]][ver[progression-1]], 1);
      break;
    case 3:
      affichage(poeme[page[4]][ver[progression-3]],
		poeme[page[4]][ver[progression-2]],
		poeme[page[5]][ver[progression-1]],
		NULL, 2);
      break;
    case 4:
      affichage(poeme[page[4]][ver[progression-3]],
		poeme[page[5]][ver[progression-2]],
		poeme[page[4]][ver[progression-1]],
	        NULL, 2);
      break;
    case 5:
      affichage(poeme[page[5]][ver[progression-3]],
		poeme[page[4]][ver[progression-2]],
		poeme[page[4]][ver[progression-1]],
		NULL, 2);
      break;
    }
}

void aleatoire(char poeme[14][10][100])
{
  //srand(time(NULL)); // on initialise la fonction rand()

  unsigned int page[6] = {0, 0, 0, 0, 0, 0}; // Contiendra le numero de chaque page selectionnes (les 4 premiers pour les 2 quatrains, les 2 derniers pour les deux tercets)
  unsigned int ver[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Contiendra le numero de la ligne de chaque vers selectionnes

  unsigned int progression = 0;
  unsigned int random = 0;
  unsigned int quatrain = 0, tercet = 0;

  random_page(page);
  printf("\n");

  while(progression < 14)
    {
      if(((rand()%2) && (quatrain < 2))||(tercet >= 2)) // selection du quatrain ou tercet
	{
	  ver_quatrain(ver, progression);

	  // affichage aleatoire : type de quatrain
	  // 0 => AABB
	  // 1 => ABBA
	  // 2 => ABAB

	  random = rand() % 3;
	  quatrain++;
	  progression += 4; // 4 vers supplementaires
	}
      else
	{
	  ver_tercet(ver, progression);

	  // affichage aleatoire : type de tercet
	  // 3 => AAB
	  // 4 => ABA
	  // 5 => BAA

	  random = rand() % 3 + 3;
	  tercet++;
	  progression += 3; // 3 vers supplementaires
	}

      rand_affichage(poeme, page, ver, progression, random, quatrain);
      printf("\n"); // Retour a la ligne entre les quatrains/tercets
    }
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
  
      aleatoire(poeme);
   }
   else
      fprintf(stderr, "\nErreur : Ouverture du fichier impossible\nAvez vous indiquer le bon chemin ?\n"); // erreur si l'ouverture du fichier est impossible
      
      fclose(fichier); // on ferme le fichier
}

int main(int nbArgs, char* args[])
{
  srand(time(NULL));
  char poeme[14][10][100]; // 14 pages, 10 lignes par pages, 100 caracteres par lignes

  if(nbArgs > 1)
    lecture(poeme, args);
  else
    fprintf(stderr, "\nErreur : Veuillez indiquer le fichier a ouvrir en parametre\n");

  return EXIT_SUCCESS;
}
