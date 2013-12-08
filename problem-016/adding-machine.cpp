#include <stdio.h>
#include <string.h>


class LargeNumber
{
private:

  static const int MAX_DIGITS = 305;
  char accumulator[MAX_DIGITS];


private:

  void initialize_accumulator(void)
  {
    for (int i = 0; i < MAX_DIGITS; i++)
      accumulator[i] = 0;
  }


public:

  LargeNumber(void)
  {
    initialize_accumulator();
    accumulator[0] = 2;
  }


  void multiply_by_two(void)
  {
    int carry = 0;

    for (int x = 0; x < MAX_DIGITS; x++)
    {
      int y = 2 * accumulator[x] + carry;

      if (y >= 10)
      {
        carry = 1;
        y = y - 10;
      }
      else
        carry = 0;

      accumulator[x] = y;
    }
  }


  int sum_of_all_digits(void)
  {
    int sum = 0;

    for (int x = 0; x < MAX_DIGITS; x++)
      sum += accumulator[x];

    return sum;
  }

};


int main(void)
{
  LargeNumber accumulator;

  for (int x = 1; x < 1000; x++)
  {
    accumulator.multiply_by_two();
  }

  printf("Sum of digits: %d\n", accumulator.sum_of_all_digits());
  return 0;
}
