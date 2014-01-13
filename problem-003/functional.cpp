#include <iostream>
#include <cmath>
#include <algorithm>


/* WARNING:
 * This must be compiled with compiler optimizations that flatten the recursion.
 *
 * ie.: g++ -O3 -o functional functional.cpp
 *
 */


class IsPrime
{
private:

  bool is_prime(const long long int x, const long long int y) const
  {
    if (x % y == 0)
      return false;
    else if (y > 3)
      return is_prime(x, y-2);
    else
      return true;
  }

public:

  bool operator()(const long long int x) const
  {
    if (x % 2 == 0) return false;
    const long long int sqrt_x = (long long int) sqrt((double) x);
    const long long int max_possible_factor = sqrt_x % 2 == 0 ? sqrt_x-1 : sqrt_x;
    return is_prime(x, std::max(max_possible_factor, (long long int) 3));
  }
};


class LargestPrimeFactor
{
private:

  IsPrime is_prime;

  long long int largest_prime_factor(const long long int x, const long long int y) const
  {
    if (x % y == 0 && is_prime(y))
      return y;
    else if (y > 3)
      return largest_prime_factor(x, y-2);
    else
      return 1;
  }

public:

  long long int operator()(const long long int x) const
  {
    const long long int sqrt_x = (long long int) sqrt((double) x);
    const long long int max_possible_factor = sqrt_x % 2 == 0 ? sqrt_x-1 : sqrt_x;
    return largest_prime_factor(x, std::max(max_possible_factor, (long long int) 3));
  }

};


int main(void)
{
  const long long int number = 600851475143;
  LargestPrimeFactor largest_prime_factor;

  std::cout << "Largest prime factor: " << largest_prime_factor(number) << std::endl;
  return 0;
}