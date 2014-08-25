#include <stdio.h>
#include <cmath>
#include <vector>


class Primes
{
private:

  const int MAX_PRIMES;
  std::vector<int> _list_of_primes;


public:

  Primes(int max)
  : MAX_PRIMES(max),
    _list_of_primes(MAX_PRIMES)
  {
    initialize_primes();
  }


  int operator[](int idx)
  {
    if (idx >= 0 && idx < MAX_PRIMES)
      return _list_of_primes[idx];
    else
      throw "Primes: Index out of range";
  }


private:

  void initialize_primes(void)
  {
    int prime_idx = 2;
    _list_of_primes[0] = 2;
    _list_of_primes[1] = 3;

    for (int n = 5; prime_idx < MAX_PRIMES; n += 2)
    {
      if (is_prime(n))
        _list_of_primes[prime_idx++] = n;
    }
  }


  bool is_prime(int n)
  {
    int max_divisor = (int) sqrt((double) n);

    for (int x = 0; _list_of_primes[x] <= max_divisor; x++)
      if (n % _list_of_primes[x] == 0)
        return false;

    return true;
  }

};


class NumberOfPrimeFactors
{
private:

  Primes &_primes;

public:

  NumberOfPrimeFactors(Primes &primes)
  : _primes(primes)
  {}


  int operator()(int n)
  {
    int factor_count = 0;
    int max_divisor = n / 2;
    for (int a = 0; _primes[a] <= max_divisor; a++)
    {
      if (n % _primes[a] == 0)
        factor_count++;
    }

    return factor_count;
  }
};


int main(void)
{
  const int MAX_PRIMES = 10000;
  const int MAX_CONSECUTIVE_COUNT = 4;
  Primes primes(MAX_PRIMES);
  NumberOfPrimeFactors factors(primes);
  int consecutive_count = 0;
  int a;

  for (a = 648; consecutive_count < MAX_CONSECUTIVE_COUNT; a++)
  {
    if (factors(a) == 4)
      consecutive_count++;
    else
      consecutive_count = 0;
  }

  printf("a: %d\n", a-4);

  return 0;
}
