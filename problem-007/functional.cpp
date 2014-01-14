#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>


typedef int number;
typedef std::vector<number> list_of_primes;


class FindPrimes
{
private:

  const number _max_number_of_primes;


  bool is_prime(const list_of_primes &primes, number candidate, int idx, number max_root) const
  {
    if (idx < primes.size())
    {
      if (primes[idx] <= max_root)
      {
        if (candidate % primes[idx] == 0)
          return false;
        else
          return is_prime(primes, candidate, idx+1, max_root);
      }
      else
        return true;
    }
    else
      throw std::runtime_error("Reached end of list");
  }


  list_of_primes find_primes(const list_of_primes &primes, const number start) const
  {
    if (primes.size() < _max_number_of_primes)
    {
      if (is_prime(primes, start, 1, (number) (sqrt((double) start) + 0.5)))
      {
        list_of_primes new_list = primes;
        new_list.push_back(start);
        return find_primes(new_list, start+2);
      }
      else
        return find_primes(primes, start+2);
    }
    else
      return primes;
  }


public:

  FindPrimes(int max)
  : _max_number_of_primes(max)
  {}

  list_of_primes operator()(void) const
  {
    list_of_primes primes;
    primes.push_back(2);
    primes.push_back(3);
    return find_primes(primes, 5);
  }

};


int main(void)
{
  FindPrimes find_primes(10001);
  list_of_primes primes = find_primes();
  std::cout << "Number of primes: " << primes.size() << std::endl;
  std::cout << "10001st number:   " << primes.back() << std::endl;
}