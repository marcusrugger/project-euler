package main

import "fmt"


func doittoit(step int, end int) int {
  var sum int = 0
  for i := 0; i < end; i += step { sum += i }
  return sum
}


func main() {
  const end = 1000
  var sum3 int = doittoit(3, end)
  var sum5 int = doittoit(5, end)
  var sum15 int = doittoit(15, end)
  fmt.Println(sum3, sum5, sum15, sum3 + sum5 - sum15)
}
