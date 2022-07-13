package main

import "fmt"

func main(){
	arr:= [5]int {1,2,3,4,5}
	fmt.Println(arr)
	s:=arr[0:3]
	fmt.Println(s)
	fmt.Println(cap(s))
}