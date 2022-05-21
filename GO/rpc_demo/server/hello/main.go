package main

import (
	"fmt"
	"net"
	"net/rpc"
)

type Hello struct {
}

func (this Hello) SayHello(req string, res *string) error {
	*res = "你好" + req
	return nil
}

func main() {
	fmt.Println("server start")
	//注册服务
	err1 := rpc.RegisterName("hello", new(Hello))
	if err1 != nil {
		fmt.Println(err1)
	}

	listener, err2 := net.Listen("tcp", "127.0.0.1:8080")
	if err2 != nil {
		fmt.Println(err2)
		return
	}
	defer listener.Close()
	for {
		conn, err3 := listener.Accept()
		if err3 != nil {
			fmt.Println(err3)
		}

		rpc.ServeConn(conn)
	}

}
