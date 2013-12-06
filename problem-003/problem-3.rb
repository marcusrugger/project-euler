require "prime"

number = 600851475143
max_x = Math.sqrt(number)
max_factor = 0

Prime.each(max_x) do |x|
  max_factor = x if number % x == 0
end

puts max_factor