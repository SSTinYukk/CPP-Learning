package main

import (
	"fmt"
	"time"
)

func newTask(){
	i:=0
	for{
		i++
		fmt.Println("new Goroutine : i=  ",i)
		time.Sleep(1*time.Second)
	}
}

func main(){
	go newTask()
	go func(){
		i:=0
		fmt.Println("Lambda Goutine.....",i)
	}()
	i:=0
	for{
		i++
		fmt.Println("main goroutine: i =",i)
		time.Sleep(1*time.Second)
	}
}