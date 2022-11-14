package leetcode

import "testing"

func TestSearchMatrix(t *testing.T) {
	martix := [][]int{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}
	target := 3
	searchMatrix(martix, target)
}
