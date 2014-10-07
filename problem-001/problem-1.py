#!/usr/bin/env python

END_OF_LOOP = 1000


step_3 = 0
for num in range(3, END_OF_LOOP, 3):
  step_3 += num

print step_3


step_5 = 0
for num in range(5, END_OF_LOOP, 5):
  step_5 += num

print step_5


step_15 = 0
for num in range(15, END_OF_LOOP, 15):
  step_15 += num

print step_15


solution = step_3 + step_5 - step_15
print solution
