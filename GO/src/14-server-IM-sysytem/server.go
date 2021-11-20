package main

import (
	"fmt"
	"net"
)

type Server struct {
	Ip   string
	Port int
}

func NewServer(ip string, port int) *Server {
	server := &Server{
		Ip:   ip,
		Port: port,
	}
	return server
}

func (t *Server) Handler(conn net.Conn) {
	fmt.Println("链接成功...")
	
}

//启动服务器的接口
func (t *Server) Start() {
	listener, err := net.Listen("tcp", fmt.Sprintf("%s:%d", t.Ip, t.Port))
	if err != nil {
		fmt.Println("net.Listen error")
		return
	}
	defer listener.Close()

	for {
		conn, err := listener.Accept()
		if err != nil {
			fmt.Println("listener accept error :", err)
			continue
		}
		go t.Handler(conn)
		
	}
}
