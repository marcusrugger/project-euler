#include <stdio.h>
#include <math.h>


class Primes
{
public:

  static int CalculatePrime(int count)
  {
    Primes primes(count);
    int rv = 5;

    while (true)
    {
      if (primes.is_prime(rv))
        if (primes.add_prime(rv) == count)
          break;

      rv += 2;
    }

    return rv;
  }


private:

  Primes(int count)
  {
    list_of_primes = new int[count];
    list_of_primes[0] = 2;
    list_of_primes[1] = 3;
    number_of_primes = 2;
  }

  ~Primes(void)
  {
    delete list_of_primes;
  }


  bool is_prime(int number)
  {
    int max_x = (int) sqrt((double) number);

    for (int x = 1; list_of_primes[x] <= max_x; x++)
      if (number % list_of_primes[x] == 0)
        return false;

    return true;
  }


  int add_prime(int number)
  {
    list_of_primes[number_of_primes++] = number;
    return number_of_primes;
  }


private:

  int *list_of_primes;
  int number_of_primes;

};


int main(void)
{
  int prime = Primes::CalculatePrime(10001);
  printf("%d\n", prime);
  return 0;
}
