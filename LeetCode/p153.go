package leetcode

func findMin(nums []int) int {
	if nums[0] > nums[len(nums)-1] {
		left, right, lenn := 0, len(nums)-1, len(nums)-1
		for left <= right {
			mid := (left + right) / 2
			if nums[mid] < nums[lenn] {
				right = mid - 1
			} else {
				left = mid + 1
			}
		}
		return nums[left]
	} else {
		return nums[0]
	}
}
