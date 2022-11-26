package leetcode

func lengthOfLongestSubstring(s string) int {
	left := 0
	right := 0
	result := 0
	need := make(map[byte]int)

	for right < len(s) {

		c := s[right]
		_, ok := need[c]
		if !ok {
			need[c]++
			if len(need) > result {
				result = len(need)
			}
			right++
			continue
		}

		for ok {

			delete(need, s[left])
			left++
			_, ok = need[s[right]]
		}
	}

	return result
}
