#include <stdio.h>
#include <stdlib.h>

int resultat(int a, char op, int b)
{
  switch(op)
    {
    case '+':
      return a+b;
      break;
    case '-':
      return a-b;
      break;
    case '*':
      return a*b;
      break;
    case '/':
      return a/b;
      break;
    case '%':
      return a%b;
      break;
    default:
      printf("Erreur\n");
      return 0;
      break;
    }
}

void afficher(int a, char op, int b, int r)
{
  printf("%d %c %d = %d\n", a, op, b, r);
}

int main()
{
  int a = 0, b = 0;
  char op = 0;

  printf("Entrez l'operation\n");
  scanf("%d %c %d", &a, &op, &b);

  afficher(a, op, b, resultat(a, op, b));

  return EXIT_SUCCESS;
}
