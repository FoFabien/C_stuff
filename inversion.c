#include <stdio.h>
#include <stdlib.h>


void inversion( char chaine[] )
{
  int n = 0;
  int i = 0;
  char tmp = 0;

  while(chaine[n]!='\0'){
    n++;
  }
  for (i=0;i<(n/2);i++){

    tmp =  chaine[i];
    chaine[i]= chaine[n-1-i];
    chaine[n-1-i]=tmp;
  }
}

int main(void){

  char chaine[50];

  printf("Entrer chaine de carateres \n");
  scanf("%s",chaine);

  inversion(chaine);

  printf("%s \n", chaine);

  return EXIT_SUCCESS;
}
    
