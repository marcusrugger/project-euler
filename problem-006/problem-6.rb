
sum_of_squares = 0
square_of_sums = 0

for a in 1..100
  square_of_sums += a
  sum_of_squares += a*a
end

square_of_sums = square_of_sums*square_of_sums

difference = square_of_sums - sum_of_squares

puts difference
