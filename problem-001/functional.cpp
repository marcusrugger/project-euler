#include <iostream>


int sum_idx(int idx, int step, int end, int sum)
{
  if (idx < end)
    return sum_idx(idx+step, step, end, sum+idx);
  else
    return sum;
}


int main(int argc, char **argv)
{
  const int end     = 1000;

  const int sum_3   = sum_idx(0, 3, end, 0);
  const int sum_5   = sum_idx(0, 5, end, 0);
  const int sum_15  = sum_idx(0, 15, end, 0);
  const int total   = sum_3 + sum_5 - sum_15;

  std::cout << "Sum: " << total << std::endl;
}
