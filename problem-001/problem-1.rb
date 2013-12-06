END_OF_LOOP = 999

sum_threes = 3.step(END_OF_LOOP, 3).inject(:+)
sum_fives  = 5.step(END_OF_LOOP, 5).inject(:+)
sum_intersection = 15.step(END_OF_LOOP, 15).inject(:+)
total_sums = sum_threes + sum_fives - sum_intersection

puts total_sums
