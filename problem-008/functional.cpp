#include <iostream>
#include <string>
#include <algorithm>
#include <memory>


static char big_number[] =  "73167176531330624919225119674426574742355349194934"
                            "96983520312774506326239578318016984801869478851843"
                            "85861560789112949495459501737958331952853208805511"
                            "12540698747158523863050715693290963295227443043557"
                            "66896648950445244523161731856403098711121722383113"
                            "62229893423380308135336276614282806444486645238749"
                            "30358907296290491560440772390713810515859307960866"
                            "70172427121883998797908792274921901699720888093776"
                            "65727333001053367881220235421809751254540594752243"
                            "52584907711670556013604839586446706324415722155397"
                            "53697817977846174064955149290862569321978468622482"
                            "83972241375657056057490261407972968652414535100474"
                            "82166370484403199890008895243450658541227588666881"
                            "16427171479924442928230863465674813919123162824586"
                            "17866458359124566529476545682848912883142607690042"
                            "24219022671055626321111109370544217506941658960408"
                            "07198403850962455444362981230987879927244284909188"
                            "84580156166097919133875499200524063689912560717606"
                            "05886116467109405077541002256983155200055935729725"
                            "71636269561882670428252483600823257530420752963450";


/* WARNING:
 * This source file requires c++11
 *
 * ie.: g++ -O2 -std=c++11 -o functional functional.cpp
 *
 */

typedef int index;

template <typename T> class Enumerator;
template <typename objType, typename retType> class IndexIterator;

template <typename T, typename U>
using foreach_fn = std::function<U(U,T)>;


template <typename T>
class Enumerator
{
private:

  const T _current;
  const T _end;
  const T _step;

public:

  Enumerator(T start, T end, T step = 1)
  : _current(start), _end(end), _step(step)
  {}

  T operator()(void) const
  { return _current; }

  bool is_more(void) const
  { return _current+_step <= _end; }

  Enumerator next(void) const
  { return Enumerator(_current+_step, _end, _step); }

  template <typename U>
  U foreach(U acc, foreach_fn<U,T> fn) const
  {
    if (is_more())
      return next().foreach(fn(acc,(*this)()),fn);
    else if (_current <= _end)
      return fn(acc,(*this)());
    else
      return acc;
  }

};


template <typename objType, typename retType>
class IndexIterator
{
private:

  const objType _obj;
  const index _idx;
  const index _step;
  const index _end;

public:

  IndexIterator(const objType &obj, const index idx, const index end, const index step = 1)
  : _obj(obj), _idx(idx), _end(end), _step(step)
  {}

  retType operator()(void) const
  { return _obj.at(_idx); }

  bool is_more(void) const
  { return _idx+_step <= _end; }

  IndexIterator next(void) const
  { return IndexIterator(_obj, _idx+_step, _end, _step); }

  //U foreach(U acc, foreach_fn<retType,U> fn) const
  template <typename U>
  U foreach(U acc, std::function<U(U,retType)> fn) const
  {
    if (is_more())
      return next().foreach(fn(acc,(*this)()),fn);
    else if (_idx <= _end)
      return fn(acc,(*this)());
    else
      return acc;
  }

};


class String
{
private:

  const std::shared_ptr<std::string> _string;

public:

  String(const String &other)
  : _string(other._string)
  {}

  String(const std::string &string)
  : _string(new std::string(string))
  {}

  String(const char *char_ptr)
  : _string(new std::string(char_ptr))
  {}

  const std::string operator()(void)
  { return (*_string); }

  char operator()(index idx)
  { return at(idx); }

  char at(index idx) const
  { return (*_string)[idx]; }

  int length(void) const
  { return _string->length(); }

  Enumerator<index> enumerator(void) const
  { return Enumerator<index>(0, length()-1); }

  Enumerator<index> enumerator(const index sidx, const index eidx) const
  {
    const index s = std::max(sidx, 0);
    const index e = std::min(eidx, length()-1);
    return Enumerator<index>(s, e);
  }

  IndexIterator<String,char> iterator(void) const
  { return IndexIterator<String,char>((*this), 0, length()-1); }

  IndexIterator<String,char> iterator(const index sidx, const index eidx) const
  {
    const index s = std::max(sidx, 0);
    const index e = std::min(eidx, length()-1);
    return IndexIterator<String,char>((*this), s, e);
  }

};


int main(void)
{
  String string = big_number;

  auto outer_loop = string.enumerator(0, string.length()-5);
  int result = outer_loop.foreach<int>(0, [&string](int a, index idx) -> int
  {
    auto inner_loop = string.iterator(idx, idx+4);
    int result = inner_loop.foreach<int>(1, [](int val, char c) -> int { return val * (c - '0'); });
    printf("Inner result: %d\n", result);
    return std::max(a, result);
  });

  std::cout << "Result: " << result << std::endl;
}
