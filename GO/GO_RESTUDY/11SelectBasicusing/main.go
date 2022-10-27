package main

import (
	"fmt"
	"runtime"
	"sync"
)

var mutex sync.Mutex
var rwmutex sync.RWMutex
func main() {
	ch := make(chan int)
	quit := make(chan bool)
	go func() {
		x, y := 1, 1
		for i := 0; i < 10; i++ {
			ch <- x
			x, y = y, x+y
		}
		close(ch)
		quit <- true
		runtime.Goexit()
	}()

	for {
		select {
		case num := <-ch:
			fmt.Println("读到", num)
		case <-quit:
			return
		}
		fmt.Println("================")
	}
}
