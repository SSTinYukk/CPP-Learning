package main 

import "fmt"

type Hero struct{
	Name string 
	Level int 
}

func (t Hero)GetName(){
	fmt.Println("Name = ",t.Name)
}

func (t *Hero)SetName(NewStr string){
	t.Name=NewStr
}

func main(){
		hero:=Hero{
			Name:"琪亚娜",
			Level: 3, 
		}
		hero.GetName()
		hero.SetName("芽衣")
		hero.GetName()
}