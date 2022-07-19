package main
import "fmt"
type speaker interface{
	speak()
}
type cat struct {}
type dog struct{}

func (c cat)speak(){
	fmt.Println("miaomiaomiao")
}

func (d dog)speak(){
	fmt.Println("wangwangwang")
}

func da(x  speaker){
	x.speak()
}

func main(){
	var c cat
	var d dog
	da(c)
	da(d)
}
