package main

import (
	"fmt"
	"net"
)


func main(){
	listener,err := net.Listen("tcp","127.0.0.1:8000")
	if err != nil{
		fmt.Println("net.Listen err:",err)
		return
	}
	conn,err:=listener.Accept()
	if err!=nil{
		fmt.Println(err)
		return
	}
	buf:=make([]byte,4096)
	n,err:=conn.Read(buf)
	if err!=nil{
		fmt.Println(err)
		return
	}
	fmt.Println("读到数据",string(buf[:n]))
}