package main

import (
	"fmt"
	"log"
	"net"
	"net/http"
	"net/rpc"
	"sync"
)

const (
	Leader = 1 << iota
	Fllower
)

type Raft struct {
	VoteFor uint
}

type Node struct {
	Term   uint
	Status uint
	NodeId uint
}

func (r *Raft) Votefor(arg *Node, reply *uint) error {
	fmt.Printf("%#v", arg)
	*reply = arg.NodeId
	return nil
}

func main() {
	wg := new(sync.WaitGroup)
	a := new(Raft)

	rpc.Register(a)
	rpc.HandleHTTP()

	listener, err := net.Listen("tcp", "127.0.0.1:8000")
	if err != nil {
		log.Fatal("listen error", err)
	}
	go http.Serve(listener, nil)
	wg.Add(1)
	wg.Wait()
}
