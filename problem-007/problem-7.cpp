#include <stdio.h>
#include <math.h>


bool is_prime(int number)
{
  int max_x = (int) sqrt((double) number);
  
  for (int x = 3; x <= max_x; x += 2)
    if (number % x == 0)
      return false;

  return true;
}


int main(void)
{
  int prime_countdown = 10001 - 2;
  int last_prime = 3;

  while (prime_countdown > 0)
  {
    int prime_candidate;
    for (prime_candidate = last_prime + 2; !is_prime(prime_candidate); prime_candidate += 2);
    last_prime = prime_candidate;
    prime_countdown--;
  }

  printf("%d\n", last_prime);
  return 0;
}
