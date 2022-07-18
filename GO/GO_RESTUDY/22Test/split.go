package split

import (
	"strings"
)

func Split(str string, seq string) []string {
	res_str := make([]string,0,len(str))
	index := strings.Index(str, seq)
	for index >= 0 {
		res_str = append(res_str, str[:index])
		str = str[index+len(seq):]
		index = strings.Index(str, seq)
	}
	res_str = append(res_str, str)
	return res_str
}
