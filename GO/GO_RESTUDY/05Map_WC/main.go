package main

import (
	"fmt"
	"strings"
)

func main() {
	str := "I love my work and I love my family too"
	m1 := make(map[string]int)
	s1 := strings.Split(str, " ")
	for _, i := range s1 {
		m1[i]+=1
	}
	fmt.Println(m1)
}
