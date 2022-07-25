package main

import (
	"log"
	"sync"
	"time"
)

var wg = new(sync.WaitGroup)
var exitChan = make(chan bool, 1)

func son() {
	defer wg.Done()
FORLOOP:
	for {
		log.Println("six")
		time.Sleep(500 * time.Millisecond)
		select {
		case <-exitChan:
			break FORLOOP
		default:

		}
	}
}

func main() {
	wg.Add(1)
	go son()
	time.Sleep(5 * time.Second)
	exitChan <- true
	wg.Wait()
}
