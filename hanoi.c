#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MIN 1
#define MAX 3
#define USAGE 2

void hanoi(int N, int from, int to, int using)
{
  if(N > 0)
    {
      hanoi(N-1, from, using, to);
      printf("deplacement %d => %d\n", from, to);
      hanoi(N-1, using, to, from);
    }
}

int main(int nbArg, char *args[])
{
  long int N;
  if(nbArg != 2)
    {
      fprintf(stderr, "usage : %s N\n", args[0]);
      return EXIT_FAILURE;
    }

  N = strtol(args[1], (char **)NULL, 10);

  if(N == LONG_MIN || N == LONG_MAX || N <= 0)
    {
      fprintf(stderr, "mauvais nombre de disque\n");
      return EXIT_FAILURE;
    }

  hanoi(N, MIN, MAX, USAGE);

  return EXIT_SUCCESS;
}
