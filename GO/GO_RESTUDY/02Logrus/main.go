package main

import (
	"os"

	"github.com/sirupsen/logrus"
)

var log = logrus.New()

func main() {
	file, err := os.OpenFile("logrus.log", os.O_APPEND, 0666)
	if err == nil {
		log.Out = file
	} else {
		log.Info("Failed to log to file")
	}

	log.WithFields(logrus.Fields{
		"filename": "123.txt",
		"Jet":      "Brains",
	}).Info("打开文件失败")
}
