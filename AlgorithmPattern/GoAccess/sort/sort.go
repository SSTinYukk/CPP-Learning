package main

import (
	"fmt"
	"sort"
)

func sortint() {
	arr := []int{0, 1, 4, 2, 3}
	sort.Ints(arr)
	fmt.Println(arr)
}

func sortstring() {
	str := []string{"阿前天", "后天", "ac", "acg", "bc"}
	sort.Strings(str)
	fmt.Println(str)
}

func main() {
	sortstring()
}
