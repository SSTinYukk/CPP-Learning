package leetcode

func searchMatrix(matrix [][]int, target int) bool {
	left, right := 0, len(matrix)-1
	wid := len(matrix[0])
	var block int
	var mid int
	for left <= right {
		mid = (left + right) / 2
		if target >= matrix[mid][0] && target <= matrix[mid][wid-1] {
			block = mid
			break
		} else if target < matrix[mid][0] {
			right = mid - 1
			if right < 0 {
				return false
			}
		} else {
			left = mid + 1
			if left > len(matrix)-1 {
				return false
			}
		}
	}
	left, right = 0, wid-1
	one := matrix[block]
	for left <= right {
		mid = (left + right) / 2
		if target == one[mid] {
			return true
		} else if target < one[mid] {
			right = mid - 1
		} else {
			left = mid + 1
		}
	}
	return false
}
