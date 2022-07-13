package main

import (
	"fmt"
	"runtime"
)

func main(){
	n:=runtime.GOMAXPROCS(1)

	for{
		go fmt.Print(0)
		fmt.Print(1)
		fmt.Print(n)
	}
}