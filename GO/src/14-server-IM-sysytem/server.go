package main

import (
	"fmt"
	"net"
	"sync"
)

type Server struct {
	Ip   string
	Port int

	//在线用户列表
	OnlineMap map[string]*User
	mapLock   sync.RWMutex
	//消息广播channel
	Message chan string
}

//监听Messag广播消息channel的goroutine 
func(t *Server)ListenMessage(){
	for{
		msg:=<-t.Message
		t.mapLock.Lock()
		for _,cli := range t.OnlineMap{
			cli.C<-msg  
		}
		t.mapLock.Unlock() 

	}
}

func NewServer(ip string, port int) *Server {
	server := &Server{
		Ip:   ip,
		Port: port,
		OnlineMap: make(map[string]*User),
		Message: make(chan string),
	}
	return server
}

func (t *Server)BroadCast(user *User,msg string){
	sendMsg := "["+user.Addr+"]"+user.Name+":"+msg

	t.Message <-sendMsg
 }


func (t *Server) Handler(conn net.Conn) {
	//...当前连接的任务

  
	//fmt.Println("链接成功...")
	user:=NewUser(conn)

	//用户上线,将用户加入到onlineMap中
	t.mapLock.Lock()
	t.OnlineMap[user.Name]=user
	t.mapLock.Unlock()

	//广播当前用户上线消息

	t.BroadCast(user,"已上线")
}

//启动服务器的接口
func (t *Server) Start() {
	listener, err := net.Listen("tcp", fmt.Sprintf("%s:%d", t.Ip, t.Port))
	if err != nil {
		fmt.Println("net.Listen error")
		return
	}
	defer listener.Close()
	//启动监听Message的goroutine
	go t.ListenMessage()
	
	for {
		conn, err := listener.Accept()
		if err != nil {
			fmt.Println("listener accept error :", err)
			continue
		}
		go t.Handler(conn)

	}
}
