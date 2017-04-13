#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void lecture(char poeme[14][10][100])
{
  FILE *fichier = NULL; // pointeur vers le fichier
  char chaine[100];

  int i = 0, j = 0; // i => page, j => ligne

  fichier = fopen("poemes.txt", "r"); // ouverture en lecture seule

  if(fichier != NULL) // verification d'ouverture
    for(i = 0; i < 14; i++)
      {
	for(j = 0; j < 10; j++)
	  {
	    fgets(poeme[i][j], 100, fichier); // on stock les vers de chaque poemes
	  }
	fgets(chaine, 100, fichier); // on fait un fgets pour la ligne vide entre chaque poemes
      }
  else
    fprintf(stderr, "Erreur : Ouverture du fichier impossible\n"); // erreur si l'ouverture du fichier est impossible

  fclose(fichier); // on ferme le fichier
}

void affichage(char poeme[14][10][100])
{
  srand(time(NULL)); // on initialise la fonction rand()

  int page[6] = {0, 0, 0, 0, 0, 0}; // Contiendra le numero de chaque page selectionnes (les 4 premiers pour les 2 quatrains, les 2 derniers pour les deux tercets)
  int ver[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Contiendra le numero de la ligne de chaque vers selectionnes

  int progression = 0;
  int i = 0;
  int quatrain = 0, tercet = 0;

  for(i = 0; i < 5; i=i+2) // On choisi les pages (on evites d'avoir les 2 memes pour un quatrain ou un tercet)
    {
      page[i] = rand()%14;
      do{
	page[i+1] = rand()%14;
      }while(page[i+1] == page[i]);
    }

  for(progression = 0; progression < 14; progression++)
    {
      if(((rand()%2) && (quatrain < 2))||(tercet >= 2)) // selection du quatrain ou tercet
	{
	  ver[progression] = rand()%10;
	  do{
	    ver[progression+1] = rand()%10;
	  }while(ver[progression+1] == ver[progression]);

	  ver[progression+2] = rand()%10;
	  do{
	    ver[progression+3] = rand()%10;
	  }while(ver[progression+3] == ver[progression+2]);

	  // affichage aleatoire : type de quatrain
	  // 1 => AABB
	  // 0 => 1 => ABBA
	  //      0 => ABAB

	  if(rand()%2)
	    {
	      for(i = 0; i < 2; i++)
		{
		  printf("%s", poeme[page[quatrain*2+i]][ver[progression+i]]); // A B
		  printf("%s", poeme[page[quatrain*2+i]][ver[progression+i+1]]); // A B
		}
	    }
	  else
	    {
	      if(rand()%2)
		{
		  printf("%s", poeme[page[quatrain*2]][ver[progression]]); // A
		  printf("%s", poeme[page[quatrain*2+1]][ver[progression+1]]); // B
		  printf("%s", poeme[page[quatrain*2+1]][ver[progression+2]]); // B
		  printf("%s", poeme[page[quatrain*2]][ver[progression+3]]); // A
		}
	      else
		{
		  printf("%s", poeme[page[quatrain*2]][ver[progression]]); // A
		  printf("%s", poeme[page[quatrain*2+1]][ver[progression+1]]); // B
		  printf("%s", poeme[page[quatrain*2]][ver[progression+2]]); // A
		  printf("%s", poeme[page[quatrain*2+1]][ver[progression+3]]); // B
		}
	    }
	  quatrain++;
	  progression += 3; // 3 + 1 = 4 vers supplementaires
	}
      else
	{
	  ver[progression] = rand()%10;
	  do{
	    ver[progression+1] = rand()%10;
	  }while(ver[progression+1] == ver[progression]);

	  ver[progression+2] = rand()%10;
	  // affichage aleatoire : type de tercet
	  // 1 => AAB
	  // 0 => 1 => ABA
	  //      0 => BAA

	  if(rand()%2)
	    {
		  printf("%s", poeme[page[4]][ver[progression]]); // A
		  printf("%s", poeme[page[4]][ver[progression+1]]); // A
		  printf("%s", poeme[page[5]][ver[progression+2]]); // B
	    }
	  else
	    {
	      if(rand()%2)
		{
		  printf("%s", poeme[page[4]][ver[progression]]); // A
		  printf("%s", poeme[page[5]][ver[progression+1]]); // B
		  printf("%s", poeme[page[4]][ver[progression+2]]); // A
		}
	      else
		{
		  printf("%s", poeme[page[5]][ver[progression]]); // B
		  printf("%s", poeme[page[4]][ver[progression+1]]); // A
		  printf("%s", poeme[page[4]][ver[progression+2]]); // A
		}
	    }
	  tercet++;
	  progression += 2; // 2 + 1 = 3 vers supplementaires
	}
      printf("\n");
    }
}

int main(void)
{
  char poeme[14][10][100]; // 14 pages, 10 lignes par pages, 100 caracteres par lignes

  lecture(poeme);
  affichage(poeme);

  return EXIT_SUCCESS;
}
