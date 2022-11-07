package leetcode

func slice_max(a []int) int {
	max := 0
	max_key := 0
	for key, v := range a {
		if v > max {
			max = v
			max_key = key
		}
	}
	return max_key
}

func topKFrequent(nums []int, k int) []int {
	a := make([]int, 100000)
	for _, value := range nums {
		a[value]++
	}
	res := make([]int, 0)
	for i := 0; i < k; i++ {
		temp := slice_max(a)
		a[temp] = 0
		res = append(res, temp)
	}
	return res
}

func SliceEqualBCE(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}

	if (a == nil) != (b == nil) {
		return false
	}

	b = b[:len(a)]
	for i, v := range a {
		if v != b[i] {
			return false
		}
	}

	return true
}
