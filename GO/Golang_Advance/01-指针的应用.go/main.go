package main

import "fmt"

func main() {
	var a int = 10

	var p *int = nil
	p = &a
	a = 100
	fmt.Println("a = ", a)
}
