package main

import (
	"net"
	"runtime"
	"strings"
	"time"

	"github.com/sirupsen/logrus"
)

func Handle(conn net.Conn){
	recbuf:=make([]byte,1024)
	sendbuf:=make([]byte,1024)
	for{
		_,err:=conn.Read(recbuf)
		if err!=nil{
			logrus.Info("Clint ",conn.RemoteAddr()," Closed.")
			runtime.Goexit()
		}

		copy(sendbuf,[]byte(strings.ToUpper(string(recbuf))))
		conn.Write(sendbuf)
	}


}


func main(){
	listener,err:=net.Listen("tcp","127.0.0.1:8001")
	if err!=nil{
		logrus.Error(err)
		return
	}
	defer listener.Close()


	for{
		conn,err:=listener.Accept()
		if err!=nil{
			logrus.Error(time.Now().UTC(),err)
			return
		}
		logrus.Info(time.Now().UTC()," Client Connected:",conn.RemoteAddr())
		defer conn.Close()
		go Handle(conn)
	}
	
}