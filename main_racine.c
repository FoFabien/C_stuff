#include "racine.c"


int main(void)
{
  int a = 0;

  printf("Donne un nombre\n");
  scanf("%d", &a);
  printf("%16.13Lf\n", racine(10, a));
  return EXIT_SUCCESS;
}
