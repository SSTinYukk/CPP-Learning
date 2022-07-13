package main

import(
	"fmt"
	"time"
)

func main(){
	mytime :=time.NewTimer(time.Second*2)
	nowtime:=<- mytime.C
	fmt.Println(nowtime)
	
}