#!/bin/sh
exec scala "$0" "$@"
!#

object Problem1
{
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
}

Problem1.main(args)
