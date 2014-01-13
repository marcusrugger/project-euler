#include <iostream>


int sum_fib(const int x, const int y, const int sum)
{
  const int z = x + y;
  if (z < 4000000)
    return sum_fib(y, z, z % 2 == 0 ? sum + z : sum);
  else
    return sum;
}


int main(int argc, char **argv)
{
  const int sum = sum_fib(1, 2, 2);
  std::cout << "Sum: " << sum << std::endl;
}