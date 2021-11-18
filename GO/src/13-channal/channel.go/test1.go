package main
import "fmt"

func main(){
	c:=make(chan int)
	go func(){
		defer fmt.Println("groutine 结束")
		fmt.Println("groutine 正在运行...")

		c <-666
	}()

	num,ret:=<-c
	fmt.Println(num,ret)
}