package main

import (
	"fmt"
	"log"
	"net/rpc"
	"os"
	"strconv"
)

type Args struct {
	A, B int
}

type Quotient struct {
	Quo, Rem int
}

func main() {

	a, _ := strconv.Atoi(os.Args[2])
	b, _ := strconv.Atoi(os.Args[3])
	client, err := rpc.DialHTTP("tcp", "127.0.0.1:1234")
	if err != nil {
		log.Fatal("dail:", err)
	}
	args := Args{a, b}
	var reply int
	err = client.Call("Arith."+os.Args[1], args, &reply)
	if err != nil {
		log.Fatal("call", err)
	}
	fmt.Printf("Arith:%d*%d=%d", args.A, args.B, reply)
}
