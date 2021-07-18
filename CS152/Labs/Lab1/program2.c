
#include <stdio.h>
#include<stdlib.h>

int
main (int argc, char *argv[])
{
  int N = 0;
  N = atoi (argv[0]);

  int outputs[6];
  for (int i = 0; i < 6; i++)
    {
      outputs[i] = 0;
    }
  int temp;

  for (int i = 0; i < N; i++)
    {
      srand (i);
      temp = rand ();
      outputs[temp % 6]++;
    }

  for (int i = 0; i < 6; i++)
    {
      temp = i + 1;
      printf (" %d  :  %d \n", temp, outputs[i]);
    }

  return 0;
}
