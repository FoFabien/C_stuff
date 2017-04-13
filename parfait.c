#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void parfait(int x)
{
  int b = 0, c = 0;

  for(b=1;b<=x;b++)
    {
      if (x%b==0)
	c=c+b;
    }
  if(c==2*x)
    printf("%d est parfait\n", x);
}

int main()
{
  int i=0;
  clock_t t = clock();

  for(i = 1; i <= 1000; i++)
  parfait(i);

  printf("%lu\n", clock() - t);

  return EXIT_SUCCESS;
}

