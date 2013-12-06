#include <stdio.h>


int main(void)
{
  const int END_OF_LOOP = 1000;

  int sum_threes = 0;
  for (int x = 3; x < END_OF_LOOP; x += 3)
    sum_threes += x;

  int sum_fives = 0;
  for (int x = 5; x < END_OF_LOOP; x += 5)
    sum_fives += x;

  int sum_intersection = 0;
  for (int x = 15; x < END_OF_LOOP; x += 15)
    sum_intersection += x;

  int total_sums = sum_threes + sum_fives - sum_intersection;
  printf("%d\n", total_sums);

  return 0;
}
