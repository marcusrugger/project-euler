#include <stdio.h>
#include <math.h>


class Prime
{
private:

  static const int MAX_RANGE = 1000000;
  static const int MAX_PRIMES = 78498;
  int _list_of_primes[MAX_PRIMES];


public:

  Prime(void)
  {
    initialize_primes();
  }


  int find_most_consecutive_primes(void)
  {
    int most_consecutive = 0;
    int most_consecutive_prime_idx = 1;

    for (int x = 1; x < MAX_PRIMES; x++)
    {
      int y = max_consecutive_primes(_list_of_primes[x]);
      if (y > most_consecutive)
      {
        most_consecutive = y;
        most_consecutive_prime_idx = x;
      }
    }

    printf("%d\n", most_consecutive);
    printf("%d\n", most_consecutive_prime_idx);
    return _list_of_primes[most_consecutive_prime_idx];
  }


private:

  int max_consecutive_primes(int n)
  {
    int most_consecutive = 0;

    for (int y = 0; y < MAX_PRIMES && _list_of_primes[y] <= n/2; y++)
    {
      int consecutive = consecutive_primes(n, y);
      if (consecutive > most_consecutive)
        most_consecutive = consecutive;
    }

    return most_consecutive;
  }


  int consecutive_primes(int n, int y)
  {
    int consecutive = 0;
    int sum = 0;

    for (int z = y; z < MAX_PRIMES && _list_of_primes[z] <= n/2; z++)
    {
      sum += _list_of_primes[z];
      consecutive++;

      if (sum >= n)
      {
        if (sum > n)
          consecutive = 0;
        break;
      }
    }

    return consecutive;
  }


private:

  void initialize_primes(void)
  {
    int prime_idx = 2;
    _list_of_primes[0] = 2;
    _list_of_primes[1] = 3;

    for (int n = 5; n < MAX_RANGE && prime_idx < MAX_PRIMES; n += 2)
    {
      if (is_prime(n))
        _list_of_primes[prime_idx++] = n;
    }

    for (int x = 0; x < 30; x++)
      printf("prime: %d\n", _list_of_primes[x]);
  }


  bool is_prime(int n)
  {
    int max_divisor = (int) sqrt((double) n);

    for (int x = 1; _list_of_primes[x] <= max_divisor; x++)
      if (n % _list_of_primes[x] == 0)
        return false;

    return true;
  }

};


int main(void)
{
  Prime prime;
  int number = prime.find_most_consecutive_primes();
  printf("%d\n", number);
  return 0;
}
