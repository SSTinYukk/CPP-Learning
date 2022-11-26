package leetcode

func minSubArrayLen(target int, nums []int) int {
	left := 0
	right := 0

	result := 0
	bestReslt := 0
	for right < len(nums) {
		result = result + nums[right]
		for result >= target {
			if right-left < bestReslt || bestReslt == 0 {
				bestReslt = right - left + 1
			}
			result = result - nums[left]
			left++

		}
		right++
	}

	return bestReslt
}
