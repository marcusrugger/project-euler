#include <stdio.h>
#include <stdlib.h>


typedef long long int n_type;


n_type f_even(n_type n)
{
  return n / 2;
}

n_type f_odd(n_type n)
{
  return 3 * n + 1;
}

n_type f(n_type n)
{
  if (n % 2 == 0)
    return f_even(n);
  else
    return f_odd(n);
}


int number_of_collatz_terms(n_type n)
{
  int count = 1;

  while (n != 1)
  {
    n = f(n);
    count++;
    if (n <= 0 || n > 100000000000)
    {
      printf("HOLY SHIT! (%d), (%lld)\n", count, n);
      exit(0);
    }
  }

  return count;
}


int main(void)
{
  int max_number_of_terms = 0;
  int n_with_max;

  for (int n = 3; n < 1000000; n++)
  {
    int number_of_terms = number_of_collatz_terms((n_type) n);
    if (number_of_terms > max_number_of_terms)
    {
      n_with_max = n;
      max_number_of_terms = number_of_terms;
    }

    if (n % 999 == 0)
      printf("%02d: max so far: (%d), (%d)\n", n, n_with_max, max_number_of_terms);
  }

  printf("n_with_max: %d\n", n_with_max);
  printf("max_number_of_terms: %d\n", max_number_of_terms);
  return 0;
}
