package main

import (
	"fmt"
	"runtime"

	"github.com/sirupsen/logrus"
)

func fib(ch chan<- int, quit chan<- bool) {
	for {
		x, y := 1, 1
		for i := 0; i < 10; i++ {
			ch <- x
			x, y = y, x+y
		}
		quit <- true
		close(ch)
		runtime.Goexit()
	}
}

func main() {
	ch := make(chan int)
	quit := make(chan bool)

	go fib(ch, quit)
	for {
		select {
		case num := <-ch:
			fmt.Print(num, " ")
		case <-quit:
			fmt.Print("\r\n")
			logrus.WithFields(logrus.Fields{
				"animal": "walrus",
				"number": 1,
				"size":   10,
			  }).Info("A walrus appears")
			return
		}
	}


}
