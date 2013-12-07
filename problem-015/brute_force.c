#include <stdio.h>


const int MAX_GRID_SIZE = 20;
long long int lattice_count;


void calculate_number_of_paths(int x, int y)
{
  if (x || y)
  {
    if (x)
      calculate_number_of_paths(x-1, y);

    if (y)
      calculate_number_of_paths(x, y-1);
  }
  else
    lattice_count++;
}


int main(void)
{
  lattice_count = 0;

  calculate_number_of_paths(MAX_GRID_SIZE, MAX_GRID_SIZE);

  printf("%lld\n", lattice_count);
  return 0;
}