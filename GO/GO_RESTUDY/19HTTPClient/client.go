package main

import (
	"fmt"
	"net"

	"github.com/sirupsen/logrus"
)

func main() {
	conn, err := net.Dial("tcp", "127.0.0.1:8080")
	if err != nil {
		logrus.Error(err)
		return
	}
	defer conn.Close()
	httpRequest := "GET /index HTTP/1.1\r\nHost:127.0.0.1:8080\r\n\r\n"
	conn.Write([]byte(httpRequest))

	buf := make([]byte, 1080)

	_, err = conn.Read(buf)
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println(string(buf))
}
