#include <stdio.h>


class Lattice
{
public:

  static const int MAX_GRID_SIZE = 20;


private:

  long long int lattice[MAX_GRID_SIZE + 1][MAX_GRID_SIZE + 1];


public:

  Lattice(void)
  {
    for (int x = 0; x <= MAX_GRID_SIZE; x++)
      for (int y = 0; y <= MAX_GRID_SIZE; y++)
        lattice[x][y] = 0;
  }

  long long int calculate_lattice_paths(int x, int y)
  {
    if (lattice[x][y] > 0)
    {
      return lattice[x][y];
    }

    if (x == MAX_GRID_SIZE && y == MAX_GRID_SIZE)
    {
      return 1;
    }

    long long int rv = 0;

    if (x < MAX_GRID_SIZE)
      rv += calculate_lattice_paths(x + 1, y);

    if (y < MAX_GRID_SIZE)
      rv += calculate_lattice_paths(x, y + 1);

    lattice[x][y] = rv;
    return rv;
  }

};



int main(void)
{
  Lattice lattice;
  long long int number_of_paths = 0;

  for (int x = Lattice::MAX_GRID_SIZE; x >= 0; x--)
    for (int y = Lattice::MAX_GRID_SIZE; y >= 0; y--)
      number_of_paths = lattice.calculate_lattice_paths(x, y);

  printf("%lld\n", number_of_paths);    
  return 0;
}
