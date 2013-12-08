
$digit_names = [ "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" ]
$digit_names_count = [ 0, 3, 3, 5, 4, 4, 3, 5, 5, 4 ]

$teen_names = [ "ten", "eleven", "twelve", "thirteen", "fourteen",
                "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" ]
$teen_names_count = [ 3, 6, 6, 8, 8, 7, 7, 9, 8, 8 ]

$tens_names = [ "", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" ]
$tens_names_count = [ 0, 3, 6, 6, 5, 5, 5, 7, 6, 6 ]

$hundred = "hundred"
$hundred_count = 7

$thousand = "thousand"
$thousand_count = 11



def count_letters(number)
  return $thousand_count if number == 1000

  total_letters = 0

  if (number >= 100)
    total_letters += $digit_names_count[number / 100]
    total_letters += $hundred_count

    number = number % 100
    total_letters += 3 unless number == 0
  end

  if (number >= 20)
    total_letters += $tens_names_count[number / 10]
    total_letters += $digit_names_count[number % 10]
  elsif (number >= 10)
    total_letters += $teen_names_count[number % 10]
  else
    total_letters += $digit_names_count[number]
  end

  return total_letters
end


puts "five is incorrect" unless count_letters(5) == 4
puts "twelve is incorrect" unless count_letters(12) == 6
puts "twenty five is incorrect" unless count_letters(25) == 10
puts "one hundred is incorrect" unless count_letters(100) == 10
puts "one hundred and one is incorrect" unless count_letters(101) == 16
puts "one hundred and thirteen is incorrect" unless count_letters(113) == 21
puts "one hundred and twenty-three is incorrect" unless count_letters(123) == 24


total_letters = 0

for x in 1..1000
  total_letters += count_letters(x)
end

puts total_letters
