
def count_divisors(number)
  divisor_count = 2
  max_divisor = Math.sqrt(number)

  for x in 2..max_divisor
    divisor_count += 2 if number % x == 0
  end

  return divisor_count
end


next_natural_number = 2
current_triangular_number = 1
number_of_divisors = 1

while (number_of_divisors <= 500)
  current_triangular_number += next_natural_number
  next_natural_number += 1
  number_of_divisors = count_divisors(current_triangular_number)
end

puts "next natural number: #{next_natural_number}"
puts "trangular number: #{current_triangular_number}"
