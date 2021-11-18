package main

import (
	"fmt"
	"reflect"
)

type User struct {
	Id   int
	Name string
	Age  int
}

func (t User) Call() {
	fmt.Println("user is called ...")
	fmt.Printf("%v\n", t)
}

func DeFileAndMethod(input interface{}) {
	inputType := reflect.TypeOf(input)
	fmt.Println("input Type is ", inputType)
	inputValue := reflect.ValueOf(input)
	fmt.Println("input Value is ", inputValue)

	/*
		1.通过Type 获取里面的字段
		2.得到每个field数据类型
		3.通过field有一个Interface()得到对应的value
	*/

	for i := 0; i < inputType.NumField(); i++ {
		field := inputType.Field(i)
		value := inputValue.Field(i).Interface()
		fmt.Printf("%s = %v =%v\n", field.Name, field.Type, value)
	}

	for j := 0; j < inputType.NumMethod(); j++ {
		Method1 := inputType.Method(j)
		fmt.Printf("%s = %v\n", Method1.Name, Method1.Type)
	}

}

func main() {
	user := User{10086, "中国移动", 30}
	DeFileAndMethod(user)
	user.Call()
}
