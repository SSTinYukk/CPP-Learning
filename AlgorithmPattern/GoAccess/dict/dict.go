package main

import "fmt"

func main() {

	m := make(map[string]int)
	m["one"] = 1
	delete(m, "one")
	m["tow"] = 2
	m["three"] = 3
	fmt.Println(m)
	for k, v := range m {
		fmt.Printf("k:%v v:%v\n", k, v)
	}
}
