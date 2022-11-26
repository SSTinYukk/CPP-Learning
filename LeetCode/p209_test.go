package leetcode

import "testing"

func TestMinSubArrayLen(t *testing.T) {
	nums := []int{1, 4, 4}
	target := 4
	minSubArrayLen(target, nums)
}
