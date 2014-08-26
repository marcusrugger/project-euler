#include <stdio.h>
#include <utility>

const int number_of_digits = 4;
int pandigital[number_of_digits];
int counter = 0;
long long int largest_prime = 2;


bool is_prime(long long int n)
{
  return true;
}


void print_pandigital(void)
{
  for (int a = 0; a < number_of_digits; a++)
    printf("%d", pandigital[a]);

  printf("\n");
}


void swap(int digit)
{
  if (digit <= 0)
  {
    printf("digit less than zero.\n");
    throw "bullshit";
  }
  else if (digit >= number_of_digits)
  {
    printf("digit greater than the number of digits: %d.\n", digit);
    throw "bullshit";
  }
  else
  {
    int t = pandigital[digit];
    pandigital[digit] = pandigital[digit-1];
    pandigital[digit-1] = t;
  }
#if 0
  {
    int t = pandigital[digit];
    pandigital[digit] = pandigital[digit+1];
    pandigital[digit+1] = t;
  }
#endif
}


void doit()
{
  long long int pd = 0;

  for (int a = 0; a < number_of_digits; a++)
    pd = 10 * pd + (long long int) pandigital[a];

  if (number_of_digits < 5)
    printf("doit: %lld\n", pd);

  counter++;

  if (pd > largest_prime && is_prime(pd))
    largest_prime = pd;
}


void flip_em(int digit)
{
  if (digit)
  {
    flip_em(digit-1);
    for (int a = 0; a < digit; a++)
    {
      swap(digit);
      doit();
      flip_em(digit-1);
    }
  }
}


int main(int argc, char **argv)
{
  for (int a = 0; a < number_of_digits; a++)
    pandigital[a] = a+1;

  doit();
  flip_em(number_of_digits - 1);

  printf("counter: %d\n", counter);
  printf("largest prime: %lld\n", largest_prime);
}
