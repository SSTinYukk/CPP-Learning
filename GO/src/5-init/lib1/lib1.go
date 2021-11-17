package lib1
//当前lib1包中的API
import "fmt"

func lib1Test(){
	fmt.Println("lib1test...")
}

func init(){
	fmt.Println("LIB1. INIT...")
	lib1Test()
}