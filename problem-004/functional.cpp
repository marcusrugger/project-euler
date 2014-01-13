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


class MaxPalindrome
{
private:

  IsPalindrome is_palindrome;
  const int min_val;
  const int max_val;

  int func2(const int x, const int y, const int max) const
  {
    if (y < max_val)
    {
      const int z = x * y;
      if (is_palindrome(z))
        return func2(x, y+1, std::max(max, z));
      else
        return func2(x, y+1, max);
    }
    else
      return max;
  }

  int func1(const int x, const int max) const
  {
    if (x < max_val)
      return func1(x+1, func2(x, min_val, max));
    else
      return max;
  }

public:

  MaxPalindrome(const int min, const int max)
  : min_val(min), max_val(max)
  {}

  int operator()(void) const
  {
    return func1(min_val, 0);
  }

};


std::string to_string(bool flag)
{ return flag ? "true" : "false"; }


int main(int argc, char **argv)
{
  const MaxPalindrome find_max(100, 1000);
  std::cout << "Max palindrome: " << find_max() << std::endl;
}
