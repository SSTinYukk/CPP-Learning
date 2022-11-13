package lintcode

import (
	"fmt"
	"testing"
)

func TestSearchRange(t *testing.T) {
	a := []int{5, 5, 5, 5, 5}
	target := 5
	res := SearchRange(a, target)
	fmt.Println(res)

}
