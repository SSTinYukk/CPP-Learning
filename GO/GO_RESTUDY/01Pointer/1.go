package main

import "fmt"

func main(){
	var a int =10
	var p *int = &a
	
	fmt.Println(a)
	*p=250
	fmt.Println(*p)
	p=new(int)
	*p =250
}