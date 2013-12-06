#include <stdio.h>


int main(void)
{
  int x = 1;
  int y = 2;
  int sum = 2;

  while (y < 4000000)
  {
    int z = x + y;
    x = y;
    y = z;

    if (z % 2 == 0)
      sum += z;
  }

  printf("%d\n", sum);
  return 0;
}