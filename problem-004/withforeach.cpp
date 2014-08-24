#include <iostream>
#include <string>
#include <algorithm>


/* WARNING:
 * This source file requires c++11
 *
 * ie.: g++ -O2 -std=c++11 -o functional functional.cpp
 *
 */


class IsPalindrome
{
private:

  bool is_palindrome(const std::string &str, const int x, const int y) const
  {
    if (str[x] == str[y] && y > 0)
      return is_palindrome(str, x+1, y-1);
    else if (y == 0)
      return true;
    else
      return false;
  }

public:

  bool operator()(const int number) const
  {
    const std::string str = std::to_string(number);
    return is_palindrome(str, 0, str.length() - 1);
  }

};


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


std::string to_string(bool flag)
{ return flag ? "true" : "false"; }


int main(int argc, char **argv)
{
  {
    Enumerator<int> sum_it(1, 99, 1);
    const int sum = sum_it.foreach(0, [](int x, int val) { return val + x; });

    std::cout << "Sum: " << sum << std::endl;
  }

  {
    Enumerator<int> it_x(100, 999, 1);

    const int result = it_x.foreach(0, [](int x, int val)
    {
      Enumerator<int> it_y(100, 999, 1);

      return it_y.foreach(val, [x](int y, int val)
      {
        IsPalindrome is_palindrome;
        const int z = x * y;
        if (is_palindrome(z))
          return std::max(val, z);
        else
          return val;
      });
    });

    std::cout << "Max palindrome: " << result << std::endl;
  }
}
