package main

import "fmt"

func dup_remove(s1 []string) []string {
	s2 := []string{}
	flag := 1
	var ss string
	s2 = s1[:1]
	for _, str := range s1 {
		for _, str2 := range s2 {
			if str == str2 {
				flag = 0
			}
			ss = str
		}
		if flag > 0 {
			s2 = append(s2, ss)
		}
		flag = 1

	}
	return s2

}

func main() {
	s1 := []string{"111", "222", "333", "111", "444"}
	fmt.Println(s1)
	s1 = dup_remove(s1)
	fmt.Println(s1)
}
