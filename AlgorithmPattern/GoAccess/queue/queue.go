package main

import "fmt"

func main() {
	//创建队列
	queue := make([]int, 0)
	//enqueue入队
	queue = append(queue, 10)
	fmt.Println(queue)
	//dequeue出队
	v := queue[0]
	queue = queue[1:]
	fmt.Println(queue)
	fmt.Println(v)
}
