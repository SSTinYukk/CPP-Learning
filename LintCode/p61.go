package lintcode

/**
 * @param a: an integer sorted array
 * @param target: an integer to be inserted
 * @return: a list of length 2, [index1, index2]
 */
func SearchRange(a []int, target int) []int {
	// write your code here

	res := make([]int, 0)
	start := 0
	end := len(a) - 1
	if end < 0 {
		res = append(res, -1, -1)
		return res
	}
	for start+1 < end {
		mid := start + (end-start)/2
		if a[mid] == target {
			right, left := mid, mid
			for right+1 <= len(a)-1 && a[right+1] == target {

				right = right + 1
			}
			for left-1 >= 0 && a[left-1] == target {
				left = left - 1
			}
			res = append(res, left, right)
			return res
		} else if a[mid] > target {
			end = mid
		} else if a[mid] < target {
			start = mid
		}

	}
	if a[start] == target {
		res = append(res, 0, 0)
		return res
	}
	if a[end] == target {
		res = append(res, len(a)-1, len(a)-1)
		return res
	}
	res = append(res, -1, -1)
	return res
}
