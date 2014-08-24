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

public:

  PentagonalNumber(int y) : QuadraticEquation(3.0, -1.0, -2.0 * (double) y)
  {}

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


const char *bool_string(bool flag)
{
  return flag ? "true" : "false";
}


int main(int argc, char **argv)
{
#if 0
  for (int a = 1; a <= 10; a++)
  {
    int p = pentagonal(a);
    PentagonalNumber pn(p);
    printf("%3d, %6.2f, %6.2f\n", p, pn.lower_solution(), pn.upper_solution());
  }
#endif

#if 0
  const double fudge = 0.00001;
  double a = 5.0;
  double b = 6.0;
  double c = 1.0;

  QuadraticEquation qe(a, b, c);

  {
    double x = qe.lower_solution();
    double y = qe.evaluate(x);
    bool eval = fabs(y) < fudge;

    printf("x = %5.2f, eval: %s\n", x, bool_string(eval));
  }

  {
    double x = qe.upper_solution();
    double y = qe.evaluate(x);
    bool eval = fabs(y) < fudge;

    printf("x = %5.2f, eval: %s\n", x, bool_string(eval));
  }
#endif

  const int MAX_LOOP = 10000;
  int lowest_d = INT_MAX;

  for (int a = 1; a < MAX_LOOP; a++)
  {
    int pa = pentagonal(a);
    //printf("a = %5d, pa = %5d\n", a, pa);

    for (int b = a + 1; b < MAX_LOOP; b++)
    {
      int pb = pentagonal(b);
      int s = pa + pb;
      int d = pb - pa;

      //printf("b = %5d, pb = %5d, s = %5d, d = %5d\n", b, pb, s, d);
      if (PentagonalNumber::is_pentagonal_number(s) &&
          PentagonalNumber::is_pentagonal_number(d) &&
          d < lowest_d)
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
