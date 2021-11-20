package main

import "fmt"

func Fibonacii(q,c chan int){
	x,y:=1,1
	for {
		select{
		case c<-x:
			x=x+y
			y=x-y
		case <-q:
			return
		}
	}	
}


func main(){
	n:=32
	c:=make(chan int)
	q:=make(chan int)
	go func(){
		for i:=0;i<n;i++{ 
			fmt.Println(<-c)
		}
		q<-0
	}()
	
	Fibonacii(q,c)
}