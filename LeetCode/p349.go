package leetcode

func notin(num []int, v int) bool {
	for _, v1 := range num {
		if v == v1 {
			return true
		}
	}
	return false
}

func intersection(nums1 []int, nums2 []int) []int {
	res := make([]int, 0)
	for _, v1 := range nums1 {
		for _, v2 := range nums2 {
			if v1 == v2 {

				if notin(res, v1) {
					res = append(res, v1)
				}
			}
		}
	}
	return res
}
