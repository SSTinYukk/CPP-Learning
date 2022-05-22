package main

import (
	"fmt"

	"github.com/apple/foundationdb/bindings/go/src/fdb"
)

func main() {
	fmt.Println("program start")
	fdb.MustAPIVersion(720)

	db := fdb.MUstOPenDefault()

	ret, e := db.Transact(func(tr fdb.Transacttion) (interface{}, error))
}
