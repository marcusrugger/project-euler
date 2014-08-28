#!/bin/sh
exec scala "$0" "$@"
!#

object Problem1
{
  def calc_sum(i: Int, step: Int, end: Int, sum: Int): Int =
  {
  if (i < end)
    return calc_sum(i+step, step, end, sum+i);
  else
    return sum;
  }

  def main(args: Array[String])
  {
    val end = 1000;

    val sum_3   = calc_sum(0, 3, end, 0);
    val sum_5   = calc_sum(0, 5, end, 0);
    val sum_15  = calc_sum(0, 15, end, 0);
    val total   = sum_3 + sum_5 - sum_15;

    println(total)
  }
}

Problem1.main(args)
