package main

import (
	"os"
	"github.com/sirupsen/logrus"
)

func main() {
	var log = logrus.New()
	// 设置日志级别为xx以及以上
	 log.SetLevel(logrus.InfoLevel)
	 //JSON在生产中一般只在使用Splunk或Logstash等工具进行日志聚合时才有用。
	 // 设置日志格式为json格式
	// log.SetFormatter(&logrus.JSONFormatter{
	// 	// PrettyPrint: true,//格式化json
	// 	TimestampFormat: "2006-01-02 15:04:05",//时间格式化
	// })
	log.SetFormatter(&logrus.TextFormatter{
		TimestampFormat: "2006-01-02 15:04:05",//时间格式化
	})
	// 设置将日志输出到标准输出（默认的输出为stderr，标准错误）
	// 日志消息输出能够是任意的io.writer类型
	log.SetOutput(os.Stdout)
    // 初始化一些公共参数
	loginit:=log.WithFields(logrus.Fields{
		"animal": "walrus",
	})
	//输出日志
	log.Info("A walrus appears")
	loginit.Info()
}