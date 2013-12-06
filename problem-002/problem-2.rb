
x = 1
y = 2
sum = 2

while y < 4000000 do
  z = x + y
  x = y
  y = z
  sum += z if z.even?
end

puts sum
