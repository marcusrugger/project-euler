MAX_VALUE = 999

for a in 1..MAX_VALUE
  for b in a+1..MAX_VALUE
    c = Math.sqrt(a*a + b*b)
    if a+b+c == 1000
      product = a*b*c
      puts product
      exit
    end
  end
end

