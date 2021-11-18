package main

import (
	"fmt"
	"reflect"
)

type resume struct{
	Name string `info:"name" doc:"我的名字"` 
	Sex  string `info:"sex"`
}

func findTag(arg interface{}){
	t:=reflect.TypeOf(arg).Elem()

	for i :=0; i<t.NumField();i++{
		 tags:=t.Field(i).Tag.Get("info")
		 fmt.Println("info: ",tags)
	}
} 

func main(){
	var re resume 
	findTag(&re)	
}