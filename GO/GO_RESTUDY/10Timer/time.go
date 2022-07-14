package main

import (
	"fmt"
	"time"
)

func main(){
	c:=time.NewTimer(time.Millisecond)
	nowtime:=<-c.C
	fmt.Println(nowtime)

} 