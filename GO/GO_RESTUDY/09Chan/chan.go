package main

import (
	"fmt"
	"runtime"
)

func main() {
	x := make(chan int)
	runtime.GOMAXPROCS(1)
	go func() {
		for {
			<-x
			fmt.Println("hello")
		}

	}()
	i := 0
	for {

		i++
		fmt.Println("world")
		x <- i

	}
}
