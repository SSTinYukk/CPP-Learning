package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	f, err := os.OpenFile("./e.txt", os.O_RDWR, 6)
	if err != nil {
		fmt.Println("create err", err)
		return
	}

	defer f.Close()
	reader := bufio.NewReader(f)
	buf, err := reader.ReadBytes('\n')
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println(string(buf))
}
