package leetcode

//偷鸡摸狗法
// func searchInsert(nums []int, target int) int {
// 	for k, v := range nums {
// 		if v == target {
// 			return k
// 		}
// 	}
// 	var rst int
// 	for k, v := range nums {
// 		if v > target {
// 			rst = k
// 			break
// 		}
// 		rst = len(nums)
// 	}
// 	return rst

// }

//二分

func searchInsert(nums []int, target int) int {
	start := 0
	end := len(nums) - 1
	for start <= end {
		mid := (end-start)/2
		if nums[mid] < target {
			start = mid + 1

		} else if nums[mid] > target {
			end = mid - 1
		} else {
			return mid
		}
	}
	return start
}

// official
func searchInsert3(nums []int, target int) int {
	l, r := 0, len(nums)-1
	for l <= r {
		mid := (l + r) / 2
		if target == nums[mid] {
			return mid
		} else if target < nums[mid] {
			r = mid - 1
		} else {
			l = mid + 1
		}
	}
	return l
}
