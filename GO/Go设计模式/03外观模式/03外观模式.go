package Facade 

import "fmt"

type CarModel struct{}

func NewCarModel() *CarModel{
	return &CarModel{}
}
func (c *CarModel)SetMode(){
	fmt.Println("CCarModel - SetModel")
}

type CarEngine struct{}
func NewCarEngine() *CarEngine{
	return &CarEngine{}
}

func (c *CarEngine) SetEngine(){
	fmt.Println("CarEngine--SetEngine")
}

type CarBody struct{
	
}