package leetcode

import "math"

func minSubArrayLen(target int, nums []int) int {
	nums = append(nums, 0)
	left := 0
	right := 0

	result := 0
	bestReslt := math.MaxInt32
	for right < len(nums)-1 {
		result = result + nums[right]
		for result >= target {
			if right-left < bestReslt {
				bestReslt = right - left
			}

			left++
			result = result - nums[left]

		}
		right++
	}
	if bestReslt == math.MaxInt32 {
		bestReslt = 0
	}
	return bestReslt
}
