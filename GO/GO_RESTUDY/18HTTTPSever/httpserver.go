package main

import (
	"io"
	"log"
	"net/http"
)

// hello world, the web server
func HelloServer(w http.ResponseWriter, req *http.Request) {
	io.WriteString(w, "hello, world!\n")
}
func main() {
	http.HandleFunc("/hello", HelloServer)
	err := http.ListenAndServe("192.168.81.131:8080", nil)
	if err != nil {
		log.Fatal("ListenAndServe: ", err)
	}
}
