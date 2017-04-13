#include <stdio.h>
#include <stdlib.h>

void afficher(int x)
{
  if(x == 1)
    printf("La chaine est un palindrome\n");
  else
    printf("La chaine n'est pas un palindrome\n");
}

char enleve_accent(char c)
{
     switch(c)
      {
      case  -32:
	c='a';
	break;
      case  156: 
	c='e';
	break;
      case  233: 
	c='e';
	break;
      case  232: 
	c='e';
	break;
      case  234: 
	c='e';
	break;
      case  235: 
	c='e';
	break;
      case  226: 
	c='a';
	break;
      case  224: 
	c='a';
	break;
      case  228: 
	c='a';
	break;
      case  238: 
	c='i';
	break;
      case  239: 
	c='i';
	break;
      case  244: 
	c='o';
	break;
      case  251: 
	c='u';
	break;
      case  249: 
	c='u';
	break;
      case  231: 
	c='c';
	break;
      }
     return c;  
}

char majuscule(char c)
{
  if((c >= 'a') && (c <= 'z'))
    {
    c = c + ('A' - 'a');
    }
  return c;
}


int test(char a, char b)
{
  a = enleve_accent(a);
  b = enleve_accent(b);
  a = majuscule(a);
  b = majuscule(b);
  
  if(a == b)
    return 1;
  else
    return 0;
}

int taille(char chaine[])
{
  int n = 0;

  while(chaine[n] != '\0')
    n++;
  return n;
}

int palindrome(char chaine[])
{
  int n = 0, x = 0, y = 0;

  n = taille(chaine);

  x = 0;
  y = n - 2;

  do
    {
      while((chaine[x] == ' ') || (chaine[x] == '.'))
	x++;

      while((chaine[y] == ' ') || (chaine[y] == '.'))
	y--;

      if(test(chaine[x], chaine[y]))
	{
	  x++;
	  y--;
	}
      else
	return 0;

    }while(x < y); 
  
  return 1;
}

int main(void)
{
  char chaine[100];

  printf("Entrez une chaine\n");
  fgets(chaine, 100, stdin);

  afficher(palindrome(chaine));
    

  return EXIT_SUCCESS;
}
