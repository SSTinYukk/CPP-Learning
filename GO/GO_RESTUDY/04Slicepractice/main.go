package main

import "fmt"

func main() {
	s := []string{"red", "", "bulue", "", "pip"}
	for key, value := range s {
		fmt.Println(key)
		fmt.Printf("%q\n", value)
	}
}
