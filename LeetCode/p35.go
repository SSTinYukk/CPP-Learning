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

// func searchInsert(nums []int, target int) int {
// 	start := 0
// 	end := len(nums) - 1
// 	last := start + (end-start)/2
// 	for start+1 < end {
// 		mid := start + (end-start)/2
// 		if nums[mid] < target {
// 			start = mid
// 			last = mid

// 		} else if nums[mid] > target {
// 			end = mid
// 		} else {
// 			return mid
// 		}
// 	}
// 	if last+1 == end {
// 		return end + 1
// 	}
// 	return last + 1
// }

// official
func searchInsert(nums []int, target int) int {
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
