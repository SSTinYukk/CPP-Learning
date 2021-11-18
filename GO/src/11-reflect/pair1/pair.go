package main

import "fmt"

type Reader interface {
	ReadBook()
}

type Writer interface {
	WriteBook()
}

type Book struct {
}

func (t *Book) ReadBook() {
	fmt.Println("Read a Book...")
}

func (t *Book) WriteBook() {
	fmt.Println("Write a Book...")
}

func main() {
	b := &Book{}
	var r Reader= b

	r.ReadBook()

	var w Writer= r.(Writer)
	w.WriteBook()

}
