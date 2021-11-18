package main

import (
	"fmt"
	"time"
)

func main(){
	c:=make(chan int)
	go func(){
		

		for i:=0;i<5;i++{ 
			c<-i
			time.Sleep(time.Second)
		}
		close(c)		
    }()
	
	for data:=range c{
		fmt.Println(data)
	}
}