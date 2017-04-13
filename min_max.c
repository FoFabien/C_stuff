#include <stdio.h>
#include <stdlib.h>

signed int min_max(signed int T[], int n, int x)
{
  int tmp;
  int i = 0;

  tmp = T[0];

  if(x == 1)
    {
      for(i = 1; i < n; i++)
	{
	  if(T[i] < tmp)
	    tmp = T[i];
	}
      return tmp;
    }
  else
    {
      for(i = 1; i < n; i++)
	{
	  if(T[i] > tmp)
	    tmp = T[i];
	}
      return tmp;
    }
}

int main(void)
{
  signed int T[10] = {0, 1, 2, 3, 10, -2, 5, 6, -4, -1};
  int n = 10;

  printf("Le minimum est : %d\n", min_max(T, n, 1));
  printf("Le maximum est : %d\n", min_max(T, n, 0));

  return EXIT_SUCCESS;
}
