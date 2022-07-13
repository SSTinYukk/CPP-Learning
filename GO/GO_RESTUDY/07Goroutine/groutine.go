package main

import (
	"fmt"
)

func main() {
	go func() {
		i:=0
		for {
			i++
			fmt.Println(i)
		}
	}()

	for {

		fmt.Println("the main ")
	}
}
