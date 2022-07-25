package main

import (
	"context"
	"log"
	"sync"
	"time"
)

var wg = new(sync.WaitGroup)

func son(ctx context.Context) {
	defer wg.Done()
FORLOOP:
	for {
		log.Println("six")
		time.Sleep(500 * time.Millisecond)
		select {
		case <-ctx.Done():
			break FORLOOP
		default:

		}
	}
}

func main() {
	ctx, cancel := context.WithCancel(context.Background())

	wg.Add(1)
	go son(ctx)
	time.Sleep(5 * time.Second)
	cancel()
	wg.Wait()
}
