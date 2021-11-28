package main

import (
	"fmt"
	"github.com/seiflotfy/cuckoofilter"
)

func main() {
	cf := cuckoo.NewFilter(100000)
	for i := 0; i < 15; i++ {
		var ok = cf.Insert([]byte("geeky ogre"))
		fmt.Println(ok)
	}
}