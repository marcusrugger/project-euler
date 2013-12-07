#include <stdio.h>
#include <string.h>
#include "fifty-digit-numbers.h"


class LargeNumber
{
public:

  LargeNumber(void)
  {
    initialize_accumulator();
  }

  LargeNumber(const char *number)
  {
    initialize_accumulator();

    int len = strlen(number);
    for (int x = len - 1, y = 0; x >= 0 && y < MAX_DIGITS; x--, y++)
      accumulator[y] = number[x] - '0';
  }


  void add(LargeNumber &number)
  {
    int carry = 0;
    for (int x = 0; x < MAX_DIGITS; x++)
    {
      int sum = accumulator[x] + number.accumulator[x] + carry;

      if (sum >= 10)
      {
        carry = 1;
        sum = sum - 10;
      }
      else
        carry = 0;

      accumulator[x] = sum;
    }
  }


  void print(void)
  {
    int x;

    // Find the first non-zero digit
    for (x = MAX_DIGITS - 1; x >= 0 && accumulator[x] == 0; x--);

    if (x > 0)
    {
      for (; x >= 0; x--)
      {
        printf("%c", accumulator[x] + '0');
      }
      printf("\n");
    }
    else
    {
      printf("0\n");
    }
  }


  void print_most_significant_ten(void)
  {
    int x;

    // Find the first non-zero digit
    for (x = MAX_DIGITS - 1; x >= 0 && accumulator[x] == 0; x--);

    if (x > 0)
    {
      for (int y = 0; x >= 0 && y < 10; x--, y++)
      {
        printf("%c", accumulator[x] + '0');
      }
      printf("\n");
    }
    else
    {
      printf("0\n");
    }
  }


  void print_least_significant_ten(void)
  {
    for (int x = 9; x >= 0; x--)
      printf("%c", accumulator[x] + '0');

    printf("\n");
  }


  int get_number_of_digits()
  {
    int x;

    // Find the first non-zero digit
    for (x = MAX_DIGITS - 1; x >= 0 && accumulator[x] == 0; x--);

    return x + 1;
  }


private:

  static const int MAX_DIGITS = 100;
  char accumulator[MAX_DIGITS];


private:

  void initialize_accumulator(void)
  {
    for (int i = 0; i < MAX_DIGITS; i++)
      accumulator[i] = 0;
  }

};


int main(void)
{
  LargeNumber accumulator;

  for (int x = 0; x < MAX_FIFTY_DIGIT_NUMBERS; x++)
  {
    LargeNumber number(fifty_digit_numbers[x]);
    accumulator.add(number);
  }

  printf("Number of digits: %d\n", accumulator.get_number_of_digits());
  accumulator.print();
  accumulator.print_most_significant_ten();
  accumulator.print_least_significant_ten();
  return 0;
}
