package main

import "fmt"

func main(){
	Map := make(map[string]string)
	Map["雷电 芽衣"]="雷之律者"
	
	defer fmt.Println(Map)
	
	Map2:= map[string]string{
		"琪亚娜":"空之律者",
	}
	defer fmt.Println(Map2)
}