
PRIME_MULTIPLE = 9699690
nonprimes = [20,18,16,15,14,12]

number = PRIME_MULTIPLE


begin
  flag = true
  nonprimes.each do |x|
    if number % x != 0
      flag = false
      break
    end
  end
  break if flag
  number += PRIME_MULTIPLE
end until false

puts number
