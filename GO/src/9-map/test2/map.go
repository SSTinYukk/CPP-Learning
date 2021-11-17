package main

import "fmt"

func printMap(Hmap map[string]string){
	for Key,value :=range Hmap{
		fmt.Println("Key=",Key)
		fmt.Println("Value=",value)
	} 
}

func main(){
	var Hmap = make(map[string]string)
	Hmap["琪亚娜"]="空之律者"
	Hmap["希儿"]="幻海梦蝶"
	printMap(Hmap)
	delete(Hmap,"琪亚娜")
	printMap(Hmap)
}