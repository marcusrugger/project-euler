#include <stdio.h>
#include <string.h>


class LargeNumber
{
private:

  static const int MAX_DIGITS = 158;
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
    accumulator[0] = 1;
  }


  void multiply_by(int multiplier)
  {
    int carry = 0;

    for (int x = 0; x < MAX_DIGITS; x++)
    {
      int y = multiplier * accumulator[x] + carry;
      accumulator[x] = y % 10;
      carry = y / 10;
    }
  }


  int sum_of_all_digits(void)
  {
    int sum = 0;

    for (int x = 0; x < MAX_DIGITS; x++)
      sum += accumulator[x];

    return sum;
  }


  void print_all_digits(void)
  {
    int x;

    // Find first non-zero digit
    for (x = MAX_DIGITS - 1; x >= 0 && accumulator[x] == 0; x--);

    for (; x >=0; x--)
      printf("%c", accumulator[x] + '0');

    printf("\n");
  }

};


int main(void)
{
  LargeNumber accumulator;

  for (int x = 2; x < 100; x++)
  {
    accumulator.multiply_by(x);
  }

  accumulator.print_all_digits();
  printf("Sum of digits: %d\n", accumulator.sum_of_all_digits());
  return 0;
}
