package main

import "fmt"

func fool(s string, a int) int {
	fmt.Printf("%s is %d fool\n", s, a)
	return 0
}

func fool2(s string ,a int )(int ,string ){
	return a,s
}

func fool3(s string ,a int)(r1 int ,r2 string){
	fmt.Println(r1)
	fmt.Println(r2)
	return	
}

func main() {
	c := fool("adc", 5)
	z,x:=fool2("zzz",4)
	fmt.Println(c)
	fmt.Println(z)
	fmt.Println(x)
	fmt.Println(fool3("aaa",34))
}
