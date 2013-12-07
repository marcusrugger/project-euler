#include <stdio.h>


int main(void)
{
  const int MAX_DIVISOR = 20;
  int number = MAX_DIVISOR;
  bool flag = false;

  do
  {
    int a;
    for (a = 2; a <= MAX_DIVISOR; a++)
    {
      if (number % a != 0)
        break;
    }

    if (a > MAX_DIVISOR)
      break;

    number += 2;
  }
  while (true);

  printf("%d\n", number);
  return 0;
}