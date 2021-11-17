package lib2

import "fmt"

func lib2Test(){
	fmt.Println("lib2test...")
}

func init(){
	fmt.Println("LIB2. INIT...")
	lib2Test()
}