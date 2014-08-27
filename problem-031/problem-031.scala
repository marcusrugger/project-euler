#!/bin/sh
exec scala "$0" "$@"
!#

object HelloWorld
{
  val coin_values = Array(1, 2, 5, 10, 20, 50, 100, 200)

  def evaluate_path(value: Int, index: Int): Int =
  {
    if (index == coin_values.length || value > 200)
      return 0
    else if (value + coin_values(index) == 200)
      return 1
    else
      return evaluate_path(value+coin_values(index), index) +
             evaluate_path(value, index+1)
  }

  def main(args: Array[String])
  {
    println("Hello, world!", evaluate_path(0, 0))
  }
}

HelloWorld.main(args)
