
def palindrome?(number)
  s = number.to_s
  l = s.length - 1
  x = 0
  while x <= l do
    return false if s[x] != s[l]
    x += 1
    l -= 1
  end
  return true
end


max_palindrome = 0

for a in 100..999
  for b in 100..999
    number = a * b
    if (palindrome?(number))
      max_palindrome = number if number > max_palindrome
    end
  end
end

puts max_palindrome
