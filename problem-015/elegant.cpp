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

    lattice[MAX_GRID_SIZE][MAX_GRID_SIZE] = 1;
  }

  long long int calculate_lattice_paths()
  {
    for (int x = Lattice::MAX_GRID_SIZE; x >= 0; x--)
      for (int y = Lattice::MAX_GRID_SIZE; y >= 0; y--)
        calculate_lattice_node(x, y);

    return lattice[0][0];
  }


private:

  void calculate_lattice_node(int x, int y)
  {
    if (x == MAX_GRID_SIZE && y == MAX_GRID_SIZE)
      return;

    long long int node_value = 0;

    if (x < MAX_GRID_SIZE)
      node_value += lattice[x+1][y];

    if (y < MAX_GRID_SIZE)
      node_value += lattice[x][y+1];

    lattice[x][y] = node_value;
  }

};



int main(void)
{
  Lattice lattice;
  long long int number_of_paths = lattice.calculate_lattice_paths();
  printf("%lld\n", number_of_paths);    
  return 0;
}
