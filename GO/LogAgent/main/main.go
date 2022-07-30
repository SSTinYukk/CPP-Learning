package main

import (
	"log"
	"time"

	"example.com/m/v2/GO/LogAgent/kafka"
	"example.com/m/v2/GO/LogAgent/taillog"
)

func run() {
	//1.读取日志
	for {
		select {
		case line := <-taillog.ReadChan():
			kafka.SendToKafka("web_log", line.Text)
		default:
			time.Sleep(time.Second)
		}
	}

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
	run()

}
