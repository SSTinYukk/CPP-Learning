package leetcode

func maxArea1(height []int) int {
	max := 0
	for k1, v1 := range height {
		for k2, v2 := range height {
			lenth := 0
			if v1 > v2 {
				lenth = v2
			} else {
				lenth = v1
			}
			temp := (k2 - k1) * lenth
			if temp > max {
				max = temp
			}
		}
	}
	return max
}

func maxArea2(height []int) int {
	max_area := 0
	left := 0
	right := len(height) - 1
	for range height {
		if height[left] > height[right] {
			temp := height[right] * (right - left)
			if temp > max_area {
				max_area = temp
			}
			right--
		} else {
			temp := height[left] * (right - left)
			if temp > max_area {
				max_area = temp
			}
			left++
		}

	}
	return max_area
}
