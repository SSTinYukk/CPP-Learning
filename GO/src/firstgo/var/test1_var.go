package main
import "fmt"
//声明全局变量  
var gaA  int =100
var gB = 200
func main() {
	var a int
	fmt.Println(a)

	var b int =100
	fmt.Println("b=",b)
	
	var c =100
	fmt.Printf("c=%d\n",c)
	fmt.Printf("ctype=%T\n",c)

	d :=10
	fmt.Println("d=",d)
	fmt.Printf("dtype=%T\n",d)

	fmt.Println(gaA)
	fmt.Println((gB))
	var xx,yy int =10,200
	fmt.Println(xx)
	fmt.Println(yy)
	var(
		vv int =100
		jj bool =false
	)
	fmt.Println(vv)
	fmt.Println(jj)
}