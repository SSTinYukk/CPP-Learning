package main

import (
	"fmt"
	"log"
	"os"
	"runtime/pprof"
	"strconv"
	"sync"
)

var m2 sync.Map

func main() {
	w, err := os.OpenFile("a.pprof", os.O_APPEND|os.O_CREATE, 0666)
	if err != nil {
		log.Fatal("OpenFile:", err)
	}

	pprof.StartCPUProfile(w)
	str := "16000000"
	ret, _ := strconv.ParseInt(str, 10, 64)
	fmt.Printf("%#v", ret)
	m2.Store(5, "ADC")
	m2.Store("5", "AD")
	value, _ := m2.Load("5")
	fmt.Println(value)
	pprof.StopCPUProfile()
}
