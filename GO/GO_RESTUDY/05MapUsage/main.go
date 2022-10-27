package main

import "fmt"

func main(){
	m1:=make(map[int](string))
	m1[0]="sss"

	if v,ok := m1[0];ok{
		fmt.Println("value=",v,"ok=",ok)
	}
	delete(m1,0)
}