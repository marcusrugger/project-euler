#include <iostream>
#include <memory>


class LargeNumber
{
private:

  const int MAX_DIGITS;
  std::unique_ptr<char[]> number;

  void initialize_number(void)
  {
    for (int a = 0; a < MAX_DIGITS; number[a++] = 0);
  }

public:

  LargeNumber(int max_digits, int value = 0)
  : MAX_DIGITS(max_digits),
    number(new char[max_digits])
  {
    initialize_number();
  }


  void set(const int n)
  {
    number[0] = n;
  }


  char operator[](const int idx)
  {
    return number[idx];
  }


  LargeNumber &sum(const LargeNumber &x, const LargeNumber &y)
  {
    int carry = 0;
    for (int a = 0; a < MAX_DIGITS; a++)
    {
      int sum = x.number[a] + y.number[a] + carry;
      carry = sum / 10;
      number[a] = sum % 10;
    }

    return *this;
  }
};


const int num_fibs = 3;


int fib_idx(int fib_term)
{
  return fib_term % num_fibs;
}


int main(int argc, char **argv)
{
  const int MAX_DIGITS = 1000;
  LargeNumber fibs[num_fibs] = { LargeNumber(MAX_DIGITS), LargeNumber(MAX_DIGITS), LargeNumber(MAX_DIGITS) };

  fibs[0].set(1);
  fibs[1].set(1);

  int fib_term = 2;

  do
  {
    fibs[fib_idx(fib_term)].sum(fibs[fib_idx(fib_term-1)], fibs[fib_idx(fib_term-2)]);
  }
  while (fibs[fib_idx(fib_term++)][MAX_DIGITS-1] == 0);

  std::cout << "Hello world: " << fib_term << std::endl;
}
