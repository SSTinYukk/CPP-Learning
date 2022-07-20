package main

import (
	"errors"
	"log"
	"net"
	"net/http"
	"net/rpc"
	"sync"
)

type Args struct {
	A, B int
}

type Quotient struct {
	Quo, Rem int
}

type Arith int

func (t *Arith) Mul(args *Args, reply *int) error {
	*reply = args.A * args.B
	return nil
}
func (t *Arith) Div(args *Args, quo *Quotient) error {
	if args.B == 0 {
		return errors.New("divide by zero")
	}
	quo.Quo = args.A / args.B
	quo.Rem = args.A % args.B
	return nil
}

func main() {
	wg := new(sync.WaitGroup)
	arith := new(Arith)
	rpc.Register(arith)
	rpc.HandleHTTP()
	listener, err := net.Listen("tcp", ":1234")
	if err != nil {
		log.Fatal("listen error:", err)
	}
	go http.Serve(listener, nil)
	wg.Add(1)
	wg.Wait()
}
