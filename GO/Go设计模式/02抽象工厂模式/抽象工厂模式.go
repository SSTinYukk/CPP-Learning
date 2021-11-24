package main

import "fmt"

type Lunch interface {
	Cook()
}

type Rise struct {
}

func (r *Rise) Cook() {
	fmt.Println("it is rise.")
}

type Tomato struct {
}

func (t *Tomato) Cook() {
	fmt.Println("it is Tomato")
}

type LunchFactory interface {
	CreateFood() Lunch
	CreateVegetable() Lunch
}

type SimpleLunchFactory struct {
}

func NewSimpleLunchFactory() LunchFactory {
	return &SimpleLunchFactory{}
}

func (s *SimpleLunchFactory) CreateFood() Lunch {
	return &Rise{}
}

func (s *SimpleLunchFactory) CreateVegetable() Lunch {
	return &Tomato{}
}

func main() {
	factory := NewSimpleLunchFactory()
	food := factory.CreateFood()
	food.Cook()
	vegetable:=factory.CreateVegetable()
	vegetable.Cook()
}
