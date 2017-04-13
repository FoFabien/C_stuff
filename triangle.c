//---------------------------------------------------------
// Auteur : Forest Fabien
// Programme pour dessiner des triangles
// 3 types possibles
// 
// Il faut envoyer en argument :
// - Le type de Triangle (1, 2 ou 3)
//---------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

void triangle_Un(int t)
{
  int i =0, j = 0;

  if(t > 0)
    {
      for(i = 1; i <= t; i++)
	{
	  for(j = 1; j <= i; j++)
	    printf("*");
	  printf("\n");
	}
    }
}

void triangle_Deux(int t)
{
  int i = 0, j = 0;

  if(t > 0)
    {
      for(i = 1; i <= t; i++)
	{
	  for(j = 1; j <= i; j++)
	    printf("*");
	  printf("\n");
	}
      for(i = t-1; i > 0; i--)
	{
	  for(j = i; j > 0; j--)
	    printf("*");
	  printf("\n");
	
	}
    }
}

void triangle_Trois(int t)
{
  int i = 0, j = 0;
  
  if(t > 0)
    {
      for(i = 1; i <= t; i++)
	{
	  for(j = t - i; j > 0; j--)
	    printf(" ");
	  for(j = 2*i - 1; j > 0; j--)
	    printf("*");
	  printf("\n");
	}
    }
}

int main(int nbArgs, char* args[])
{
  int t = 0;

  if(nbArgs > 1)
    {
    printf("Donnez la taille\n");
    scanf("%d", &t);

    switch(atoi(args[1]))
      {
      case 2:
	triangle_Deux(t);
	break;
      case 3:
	triangle_Trois(t);
	break;
      default:
	triangle_Un(t);
	break;
      }
    }
  else
    printf("Erreur : veuillez indiquer le type de Triangle en argument\n");
 
  return EXIT_SUCCESS;
}
