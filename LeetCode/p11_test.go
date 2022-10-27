package leetcode

import (
	"fmt"
	"testing"
)

func TestMaxArea1(t *testing.T) {
	q := []int{1, 8, 6, 2, 5, 4, 8, 3, 7}
	a := maxArea1(q)
	if a == 49 {
		t.Log("Pass")
	} else {
		t.Error("Not ture")
		fmt.Printf("value a:%v", a)
	}
}

func TestMaxArea2(t *testing.T) {
	q := []int{1, 8, 6, 2, 5, 4, 8, 3, 7}
	a := maxArea2(q)
	if a == 49 {
		t.Log("Pass")
	} else {
		t.Error("Not ture")
		fmt.Printf("value a:%v", a)
	}
}
