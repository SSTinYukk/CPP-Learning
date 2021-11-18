package main

import "fmt"


type Book struct{
	author string
	name string 
	price  int 
}

func myFunc(arg interface{}){
	fmt.Println(arg)

	value,ok :=arg.(string)
	if !ok{
		fmt.Println("arg is not a string type")
	}else{
		fmt.Println("arg is string ,value = ",value)
	}
}

func main(){
	book := Book{"CC","Golang",35}
	myFunc(book)
}