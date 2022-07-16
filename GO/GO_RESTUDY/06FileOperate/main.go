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
	for {
		r, _, err := reader.ReadRune()
		if err != nil {
			fmt.Println(err)
			break
		}
		fmt.Print(string(r))
	}
	write := bufio.NewWriter(os.Stdout)
	
	write.WriteString("6666\n")
	write.Flush()
	fmt.Println("Wich")
}
