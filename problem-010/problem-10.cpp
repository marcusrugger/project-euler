#include <stdio.h>
#include <math.h>


class Primes
{
public:

  static long long int CalculateSumOfPrimes(int count)
  {
    Primes primes(count);
    int prime_candidate = 5;

    while (prime_candidate < count)
    {
        primes.add_prime(prime_candidate);
        prime_candidate += 2;
    }

    return primes.get_sum_of_primes();
  }


private:

  Primes(int count)
  {
    list_of_primes = new int[count];
    list_of_primes[0] = 2;
    list_of_primes[1] = 3;
    number_of_primes = 2;
    sum_of_primes = 5;
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
    if (is_prime(number))
    {
      sum_of_primes += number;
      list_of_primes[number_of_primes++] = number;
    }

    return number_of_primes;
  }


  long long int get_sum_of_primes(void)
  {
    return sum_of_primes;
  }


private:

  int *list_of_primes;
  int number_of_primes;
  long long int sum_of_primes;

};


int main(void)
{
  long long int sum_of_prime = Primes::CalculateSumOfPrimes(2000000);
  printf("%lld\n", sum_of_prime);
  return 0;
}
