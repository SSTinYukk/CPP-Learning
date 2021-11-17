package main

import "fmt"

type Human struct{
	name 	string
	sex		string
}
func (t *Superman) Eat(){
	fmt.Println("Superman EAT()..")
}
func (t *Human)Walk(){
	fmt.Println("Human WALK(...")
}

type Superman struct{
	Human
	level int
}

func main(){
	var s Superman
	s.name="zhangsan"
	s.sex="male"
	s.level=3
	s.Eat()
	s.Walk()
	fmt.Println(s)
}