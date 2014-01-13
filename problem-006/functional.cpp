#include <iostream>
#include <string>
#include <algorithm>


/* WARNING:
 * This source file requires c++11
 *
 * ie.: g++ -O2 -std=c++11 -o functional functional.cpp
 *
 */


template <typename T> class Enumerator;

template <typename T>
using foreach_fn = std::function<const T(const T, const T)>;


template <typename T>
class Enumerator
{
private:

  const T _current;
  const T _end;
  const T _step;

public:

  Enumerator(T start, T end, T step)
  : _current(start), _end(end), _step(step)
  {}

  T operator()(void) const
  { return _current; }

  bool is_more(void) const
  { return _current+_step <= _end; }

  Enumerator next(void) const
  { return Enumerator(_current+_step, _end, _step); }

  T foreach(T val, foreach_fn<T> fn) const
  {
    if (is_more())
      return next().foreach(fn((*this)(), val), fn);
    else
      return fn((*this)(), val);
  }

};


typedef long long int number_type;

int main(int argc, char **argv)
{
  Enumerator<number_type> sum_it(1, 100, 1);
  const number_type sum = sum_it.foreach(0, [](number_type x, number_type val) { return val + x; });
  const number_type sum_of_squares = sum_it.foreach(0, [](number_type x, number_type val) { return val + x*x; });
  const number_type square_of_sums = sum*sum;

  std::cout << "Sum of squares: " << sum_of_squares << ", Square of sums: " << square_of_sums << std::endl;
  std::cout << "Difference: " << (square_of_sums - sum_of_squares) << std::endl; 
}
