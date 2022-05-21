package main

import (
	"fmt"
	"net/rpc"
)

func main() {
	fmt.Println("client")

	conn, err1 := rpc.Dial("tcp", "127.0.0.1:8080")
	if err1 != nil {
		fmt.Println(err1)
		return
	}
	defer conn.Close()
	var reply string
	err := conn.Call("hello.SayHello", "SanSan", &reply)
	if err != nil {
		fmt.Println("Call:", err)
		return
	}
	fmt.Println(reply)
}
