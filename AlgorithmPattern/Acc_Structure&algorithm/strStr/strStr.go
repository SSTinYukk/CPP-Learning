package main

import "fmt"

func strStr(haystack, needle string) int {
	res := 0
	for hi := range haystack {
		res = hi
		ni := hi
		for i, nv := range needle {
			if rune(haystack[ni]) != nv {
				break
			}
			if i == len(needle)-1 {
				return res
			}
			ni = ni + 1
		}

	}
	return -1
}
func main() {
	res := strStr("This is No.1", "No")
	fmt.Println(res)
}
