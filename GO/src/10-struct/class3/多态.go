package main

import (
	"fmt"
)

type Animal interface {
	Sleep()
	GetColor()
	GetType()
}

type Cat struct {
	color string
}

type Dog struct {
	color string
}

func (t *Cat) Sleep() {
	fmt.Println("Cat is Sleeping...")
}
func (t *Dog) Sleep() {
	fmt.Println("Dog is Sleeping...")
}

func main() {
	var s Cat
	var d Dog
	s.color = "red"
	d.color = "blue"
	s.Sleep()
	d.Sleep()
}
