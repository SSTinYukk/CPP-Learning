package algorithmpattern

import "fmt"

func Stack(stack []int, num int) int {
	//创建栈
	//push压入
	stack = append(stack, num)
	//pop弹出
	v := stack[len(stack)-1]
	stack = stack[:len(stack)-1]
	fmt.Println(v)
	return v
}

