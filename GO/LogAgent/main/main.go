package main

import (
	"log"

	"example.com/m/v2/GO/LogAgent/kafka"
	taillog "example.com/m/v2/GO/LogAgent/tailog"
)

func run() {
	//1.读取日志
	//2.发送到kafka
}

func main() {
	err := kafka.Init([]string{"127.0.0.1:9092"})
	if err != nil {
		log.Fatal("kafka init failed", err)
		return
	}
	err = taillog.Init("./a.log")
	if err != nil {
		log.Fatal(err)
		return
	}

}
