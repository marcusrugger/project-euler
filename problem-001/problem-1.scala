#!/bin/sh
exec scala "$0" "$@"
!#

class CalcSum(step: Int, end: Int)
{
  require(step > 0)
  require(end > 0)

  var _step: Int = step
  var _end: Int = end

  def doit(i: Int): Int =
  {
    if (i < _end)
      return doit(i+_step) + i;
    else
      return 0;
  }
}


object Problem1
{
  def main(args: Array[String])
  {
    val end = 1000;

    val sum3 = new CalcSum(3, end)
    val sum5 = new CalcSum(5, end)
    val sum15 = new CalcSum(15, end)
    val total = sum3.doit(0) + sum5.doit(0) - sum15.doit(0);

    println(total)
  }

/*
  def calc_sum(i: Int, step: Int, end: Int): Int =
  {
    if (i < end)
      return calc_sum(i+step, step, end) + i;
    else
      return 0;
  }

  def main(args: Array[String])
  {
    val end = 1000;

    val sum_3   = calc_sum(0, 3, end);
    val sum_5   = calc_sum(0, 5, end);
    val sum_15  = calc_sum(0, 15, end);
    val total   = sum_3 + sum_5 - sum_15;

    println(total)
  }
*/
}

Problem1.main(args)
