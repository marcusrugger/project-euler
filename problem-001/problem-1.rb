
sum_threes = 3.step(999, 3).inject(:+)
sum_fives  = 5.step(999, 5).inject(:+)
sum_intersection = 15.step(999, 15).inject(:+)
total_sums = sum_threes + sum_fives - sum_intersection

puts total_sums
