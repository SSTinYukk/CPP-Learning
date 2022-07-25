package main

import (
	"fmt"
	"log"
	"net/rpc"
)

type Raft struct {
	VoteFor uint
}

type Node struct {
	Term   uint
	Status uint
	NodeId uint
}

func main() {
	conn, err := rpc.DialHTTP("tcp", "127.0.0.1:8000")
	if err != nil {
		log.Fatal("dial error", err)
	}
	a := Node{
		Term:   1,
		Status: 1,
		NodeId: 233,
	}
	var reply uint
	conn.Call("Raft.Votefor", &a, &reply)
	fmt.Print(reply)
}
