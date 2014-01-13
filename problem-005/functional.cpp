#include <iostream>


bool is_divisible_by(int val, int x)
{
  if (x > 2 && val % x == 0)
    return is_divisible_by(val, x-1);
  else if (x == 2)
    return true;
  else
    return false;
}


int find_number(int x = 20)
{
  if (is_divisible_by(x, 20))
    return x;
  else if (x < 1000000000)
    return find_number(x+1);
  else
    return 0;
}


int main(void)
{
  int x = find_number();
  std::cout << "number: " << x << std::endl;
}