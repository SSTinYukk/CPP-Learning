package main

import (
	"fmt"
	"strconv"
)

func test1() {
	str := []int{1, 2, 3, 4, 5, 6, 7, 8}
	copy(str[3:], str[3+1:])
	fmt.Println(str)
}
func test2() {
	a := make([]int, 10)
	a[9] = 1
	fmt.Println(a)
	s := strconv.Itoa(a[9])
	fmt.Printf("%#v", s)
}


func main() {
	test1()
	test2()
}
