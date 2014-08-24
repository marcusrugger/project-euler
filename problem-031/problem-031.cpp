#include <stdio.h>

const int TARGET_VALUE = 200;
const int coin_values[] = { 1, 2, 5, 10, 20, 50, 100, 200, 0 };

int evaluate_path(int cv_index, int sum)
{
  if (coin_values[cv_index] == 0 || sum + coin_values[cv_index] > TARGET_VALUE)
    return 0;
  else if (sum + coin_values[cv_index] == TARGET_VALUE)
    return 1;
  else
    return evaluate_path(cv_index, sum + coin_values[cv_index]) +
           evaluate_path(cv_index + 1, sum);
}

int main(int argc, char **argv)
{
  printf("Total number of solutions: %d\n", evaluate_path(0, 0));
}