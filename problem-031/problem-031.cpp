#include <stdio.h>


int main(int argc, char **argv)
{
  const int TARGET_VALUE = 200;
  const int coin_values[] = { 200, 100, 50, 20, 10, 5, 2, 1, 0 };
  int solutions_count = 0;

  for (int cv_outer_index = 0; coin_values[cv_outer_index]; cv_outer_index++)
  {
    int summed_value = 0;

    for (int cv_inner_index = cv_outer_index; summed_value < TARGET_VALUE; cv_inner_index++)
    {
      do
      {
        if (summed_value + coin_values[cv_inner_index] <= TARGET_VALUE)
          summed_value += coin_values[cv_inner_index];
        else
          break;
      }
      while (true);
    }

    solutions_count++;
  }

  printf("Total number of solutions: %d\n", solutions_count);
}