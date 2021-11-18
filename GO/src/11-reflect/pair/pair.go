package main

import "fmt"

func main(){
	var a string
	a = "abcd"

	var allType interface{}
	allType =a 

	str,ok:=allType.(string)

	fmt.Println(allType)
	fmt.Println(str,ok)
}