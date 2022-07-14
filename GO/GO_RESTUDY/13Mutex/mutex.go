package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

var rwMutex sync.RWMutex

func readgo(in <-chan int, idx int) {
	for {
		rwMutex.RLock()
		num := <-in
		rwMutex.RUnlock()
		fmt.Println("===读Go程", idx, "Read:", num)
		time.Sleep(time.Millisecond*100)
	}

}
func writego(out chan<- int, idx int) {
	for {
		rwMutex.Lock()
		num := rand.Intn(1000)
		out <- num
		rwMutex.Unlock()
		fmt.Println("写Go程", idx, "Write:", num)
		time.Sleep(time.Millisecond*100)
	}

}

func main() {
	rand.Seed(time.Now().UnixNano())
	ch := make(chan int)
	for i := 0; i < 5; i++ {
		go readgo(ch, i)
	}
	for i := 0; i < 5; i++ {
		go writego(ch, i)
	}
	time.Sleep(3 * time.Second)
}
