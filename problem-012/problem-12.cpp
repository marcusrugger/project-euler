#include <stdio.h>
#include <math.h>


int count_divisors(int number)
{
  int divisor_count = 2;
  int max_divisor = (int) sqrt((double) number);

  for (int x = 2; x <= max_divisor; x++)
  {
    if (number % x == 0)
    {
      divisor_count += 2;
    }
  }

  return divisor_count;
}


int main(void)
{
  int next_natural_number = 2;
  int current_triangular_number = 1;
  int number_of_divisors = 1;

  while (number_of_divisors <= 500)
  {
    current_triangular_number += next_natural_number++;
    number_of_divisors = count_divisors(current_triangular_number);
  }

  printf("next natural number: %d\n", next_natural_number);
  printf("trangular number: %d\n", current_triangular_number);
  return 0;
}
