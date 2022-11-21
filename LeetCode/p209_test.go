package leetcode

import "testing"

func TestMinSubArrayLen(t *testing.T) {
	nums := []int{1, 2, 3, 4, 5}
	target := 15
	minSubArrayLen(target, nums)
}
