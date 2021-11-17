package main
import "fmt"

func main(){
	var numbers = make([]int,3,5)
	numbers = append(numbers,4)
	numbers = append(numbers,4)
	numbers = append(numbers,4)
	fmt.Printf("len =  %d ,cap = %d ,slice = %v\n",len(numbers),cap(numbers),numbers)

	var s =make([]int,6,10)
	copy(s,numbers)
	fmt.Println(s,len(s),cap(s)) 
	
}