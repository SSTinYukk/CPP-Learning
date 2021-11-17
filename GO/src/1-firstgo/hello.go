package main

import "fmt"

// 返回一个“返回int的函数”
func fibonacci() func() int {
  var count,sum1,sum2 int = 0,1,1
  
  return func() int {
	  switch count{
	  case 0,1:
		  count++
	  default:
		sum1,sum2=sum2,sum1+sum2
	  }
	  return sum2
  }
}

func main() {
	f := fibonacci()
	for i := 0; i < 10; i++ {
		fmt.Println(f())
	}
}
