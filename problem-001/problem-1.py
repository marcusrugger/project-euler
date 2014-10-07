#!/usr/bin/env python

END_OF_LOOP = 1000


def calc_sum(step):
  sum = 0
  for num in range(step, END_OF_LOOP, step):
    sum += num
  return sum


print calc_sum(3) + calc_sum(5) - calc_sum(15)
