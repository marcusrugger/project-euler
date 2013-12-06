#include <stdio.h>
#include <math.h>


bool is_prime(long long int number)
{
  long long int max_x = (long long int) sqrt((double) number);

  for (long long int x = 3; x <= max_x; x += 2)
  {
    if (number % x == 0)
      return false;
  }

  return true;
}


int main(void)
{
  long long int number = 600851475143;
  long long int max_x = (long long int) sqrt((double) number);
  long long int max_factor = 0;

  for (long long int x = 3; x <= max_x; x += 2)
  {
    if (number % x == 0 && is_prime(x))
      max_factor = x;
  }

  printf("%lld\n", max_factor);
  return 0;
}