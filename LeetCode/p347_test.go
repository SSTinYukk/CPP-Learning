package leetcode

import (
	"fmt"
	"testing"
)

func TestTopkFrequent(t *testing.T) {
	a := []int{1, 1, 1, 2, 2, 3}
	k := 2
	res := topKFrequent(a, k)
	b := []int{1, 2}
	if SliceEqualBCE(res, b) {

	} else {
		t.Error("fail")
		fmt.Println(res)
	}
}
