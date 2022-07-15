package main

import (
	"fmt"
	"net"

	"github.com/sirupsen/logrus"
)

func Recv(r []byte) {
	fmt.Println(string(r))
}
func Write(conn net.Conn, w []byte) {
	var str string
	fmt.Scanf("%s", &str)
	copy(w, []byte(str))
	_, err := conn.Write(w)
	if err != nil {
		logrus.Error("发送数据失败:", err)
	}

}

func main() {
	conn, err := net.Dial("tcp", "127.0.0.1:8001")
	if err != nil {
		logrus.Error(err)
		return
	}
	defer conn.Close()
	recive_buf := make([]byte, 1024)
	send_buf := make([]byte, 1024)
	for {
		go Write(conn, send_buf)
		_, err := conn.Read(recive_buf)
		if err != nil {
			logrus.Error(err)
			return
		}
		go Recv(recive_buf)
	}
}
