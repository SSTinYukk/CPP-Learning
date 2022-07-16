package main

import "net/http"

func Handle(w http.ResponseWriter,r *http.Request){
	w.Write([]byte("</h>服务器正在维护</h>"))
}

func main(){
	http.HandleFunc("/index",Handle)

	http.ListenAndServe("127.0.0.1:8080",nil)
	
}