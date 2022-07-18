package main

import (
	"fmt"
	"io"
	"os"
	"reflect"
)

func main() {
	t := reflect.TypeOf(3.1)
	fmt.Println(t.String())
	fmt.Println(t)
	
	var w io.Writer=os.Stdout
	fmt.Println(reflect.TypeOf(w))
}
