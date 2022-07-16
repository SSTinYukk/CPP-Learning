package split

import (
	"strings"
)

func Split(str string, seq string) []string {
	res_str := make([]string,0)
	index := strings.Index(str, seq)
	flag := 1
	for index >= 0 {
		res_str = append(res_str, str[:index])
		str = str[index+len(seq):]
		index = strings.Index(str, seq)
		flag = 0
	}
	res_str = append(res_str, str)
	if flag == 1 {
		res_str = append(res_str, str)
	}
	return res_str
}
