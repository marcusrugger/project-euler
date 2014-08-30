#include <iostream>


class CalcSum
{
private:

  const int _step;
  const int _end;

public:

  CalcSum(int step, int end)
  : _step(step), _end(end)
  {}

  int operator()(int i = 0) const
  {
    if (i < _end)
      return (*this)(i+_step) + i;
    else
      return 0;
  }
};


int main(int argc, char **argv)
{
  const int end = 1000;

  const CalcSum sum3(3, end);
  const CalcSum sum5(5, end);
  const CalcSum sum15(15, end);
  const int total = sum3() + sum5() - sum15();

  std::cout << "Sum: " << total << std::endl;
}


#if 0
int sum_idx(int i, int step, int end)
{
  if (i < end)
    return sum_idx(i+step, step, end) + i;
  else
    return 0;
}


int main(int argc, char **argv)
{
  const int end     = 1000;

  const int sum_3   = sum_idx(0, 3, end);
  const int sum_5   = sum_idx(0, 5, end);
  const int sum_15  = sum_idx(0, 15, end);
  const int total   = sum_3 + sum_5 - sum_15;

  std::cout << "Sum: " << total << std::endl;
}
#endif
