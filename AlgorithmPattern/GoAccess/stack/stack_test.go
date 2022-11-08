package algorithmpattern

import (
	"log"
	"testing"
)

func TestStack(t *testing.T) {
	stack := make([]int, 0)
	num := Stack(stack, 10)
	if num == 10 {
		log.Println("Program Pass")
	} else {
		log.Fatal("fatal error", num)
	}
}
