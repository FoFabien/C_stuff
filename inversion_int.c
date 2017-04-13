#include <stdio.h>
#include <stdlib.h>


void inversion( int tableau[], int n )
{
  int i = 0;
  int tmp = 0;

  for (i=0;i<(n/2);i++){

    tmp =  tableau[i];
    tableau[i]= tableau[n-1-i];
    tableau[n-1-i]=tmp;
  }
}

int main(void){

  int tableau[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int i = 0;

  inversion(tableau, 10);

  for(i = 0; i < 10; i++)
    printf("%d ", tableau[i]);
  printf("\n");

  return EXIT_SUCCESS;
}
    
