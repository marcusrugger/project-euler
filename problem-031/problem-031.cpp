#include <stdio.h>


int main(int argc, char **argv)
{
  const int TARGET_VALUE = 200;
  const int coin_values[] = { 200, 100, 50, 20, 10, 5, 2, 1, 0 };

  for (cv_outer_index = 0; coin_values[cv_outer_index]; cv_outer_index++)
  {
    for (cv_inner_index = cv_outer_index; coin_values[cv_inner_index]; cv_inner_index++)
    {
      int summed_value = coin_values[cv];
      while (summed_value < TARGET_VALUE)
    }
  }

  printf("Hello world!\n");
}