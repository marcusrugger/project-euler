package main

import "fmt"

func main() {
  const end = 1000
  var sum3, sum5, sum15 int
  for i := 0; i < end; i += 3 { sum3 += i }
  for i := 0; i < end; i += 5 { sum5 += i }
  for i := 0; i < end; i += 15 { sum15 += i }
  fmt.Println(sum3, sum5, sum15, sum3 + sum5 - sum15)
}
