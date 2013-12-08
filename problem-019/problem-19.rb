
$days_in_month =
[
  31, # January
  28, # Febuary
  31, # March
  30, # April
  31, # May
  30, # June
  31, # July
  31, # August
  30, # September
  31, # October
  30, # November
  31  # December
]

JANUARY = 0
FEBUARY = 1
DECEMBER = 11


def add_leap_day(year)
  return 0 if year == 1900
  return 0 if year % 4 != 0
  return 1
end


def calculate_next_day_of_week(year, month, day_of_week)
  day_of_week += $days_in_month[month]
  day_of_week += add_leap_day(year) if month == FEBUARY
  day_of_week = day_of_week % 7
  return day_of_week
end






puts "Leap day is wrong for 1900" unless add_leap_day(1900) == 0
puts "Leap day is wrong for 1901" unless add_leap_day(1901) == 0
puts "Leap day is wrong for 1902" unless add_leap_day(1902) == 0
puts "Leap day is wrong for 1903" unless add_leap_day(1903) == 0
puts "Leap day is wrong for 1904" unless add_leap_day(1904) == 1
puts "Leap day is wrong for 2000" unless add_leap_day(2000) == 1





# Jan 1, 1900 was on a Monday (Sunday = 0...Saturday = 6)
day_of_week = 1
number_of_sundays = 0

for year in 1900..2000
  for month in JANUARY..DECEMBER
    number_of_sundays += 1 if year > 1900 && day_of_week == 0
    day_of_week = calculate_next_day_of_week(year, month, day_of_week)
  end
end

puts number_of_sundays
