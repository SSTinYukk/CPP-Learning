package main
import "fmt"


func printArray(myArray1 [4]int){
	for index,value:=range myArray1{
		fmt.Println("index = ",index,",value = ",value)
	}
}

func main(){
	var myArray1 [4]int
	myArray2 := []int {0,1,2,3,4,5,6,7,8,9,5,6,7}
	myArray2 = myArray2[0:10]
	for i:=0;i<len(myArray1);i++{
		fmt.Println(myArray1[i]) 
		fmt.Println(myArray2[i])
	}
	printArray(myArray1)
}