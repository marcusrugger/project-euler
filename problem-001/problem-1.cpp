#include <stdio.h>

const int END_OF_LOOP = 1000;


int calc_sum(int step)
{
  int sum = 0;

  for (int a = 0; a < END_OF_LOOP; a += step)
    sum += a;

  return sum;
}


int main(void)
{
  printf("%d\n", calc_sum(3) + calc_sum(5) - calc_sum(15));
  return 0;
}
