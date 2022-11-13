package leetcode

import (
	"log"
	"testing"
)

func TestSearch(t *testing.T) {
	nums := []int{1, 0, 3, 5, 9, 12}
	target := 9
	output := 4
	res := search(nums, target)
	if res == output {
		log.Println("Pass")
	} else {
		log.Fatalln("bad ans :", res)
	}
}
