#include <stdio.h>
#include <climits>
#include <cmath>
#include <algorithm>


class QuadraticEquation
{
private:

  double _a, _b, _c;
  double _ps, _ns;

  double quadratic_solution_radical(double a, double b, double c)
  {
    double ur = b*b - 4 * a * c;

    if (ur < 0.0)
      throw "Imaginary solution";
    else
      return sqrt(ur);
  }

  double solve(double a, double b, double c, double radical)
  {
    return (-b + radical) / (2 * a);
  }

public:

  QuadraticEquation(double a, double b, double c)
  : _a(a), _b(b), _c(c)
  {
    if (a == 0.0)
      throw "a == 0, divide by zero";

    double radical = quadratic_solution_radical(a, b, c);

    _ps = solve(a, b, c, radical);
    _ns = solve(a, b, c, -radical);
  }

  double evaluate(double x)
  {
    return _a*x*x + _b*x + _c;
  }

  double positive_radical(void)
  {
    return _ps;
  }

  double negative_radical(void)
  {
    return _ns;
  }

  double lower_solution(void)
  {
    return std::min(positive_radical(), negative_radical());
  }

  double upper_solution(void)
  {
    return std::max(positive_radical(), negative_radical());
  }
};


class PentagonalNumber : public QuadraticEquation
{
private:

  static bool is_integer(double n)
  {
    const double fudge = 0.00001;
    double ipart;
    double fpart = modf(n, &ipart);
    return fabs(fpart) < fudge;
  }

  PentagonalNumber(int y) : QuadraticEquation(3.0, -1.0, -2.0 * (double) y)
  {}

public:

  static bool is_pentagonal_number(int y)
  {
    PentagonalNumber pn(y);

    return is_integer(pn.upper_solution());
  }
};


int pentagonal(int n)
{
  return n * (3*n - 1) / 2;
}


int main(int argc, char **argv)
{
  const int MAX_LOOP = 10000;
  int lowest_d = INT_MAX;

  for (int a = 1; a < MAX_LOOP; a++)
  {
    int pa = pentagonal(a);

    for (int b = a + 1; b < MAX_LOOP; b++)
    {
      int pb = pentagonal(b);
      int s = pa + pb;
      int d = pb - pa;

      if (d < lowest_d &&
          PentagonalNumber::is_pentagonal_number(s) &&
          PentagonalNumber::is_pentagonal_number(d))
      {
        lowest_d = d;
      }
    }
  }

  if (lowest_d < INT_MAX)
    printf("d = %d\n", lowest_d);
  else
    printf("No match.\n");
}
