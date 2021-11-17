package main

import "fmt"

type Book struct {
	bookname string
	pages    int
}

func change(book *Book) {
	book.bookname = "C++"
	book.pages = 543
}

func main() {

	var C_Prime_Plus Book
	C_Prime_Plus.bookname = "C_Prime_Plus"
	C_Prime_Plus.pages = 493
	fmt.Println(C_Prime_Plus)
	change(&C_Prime_Plus)
	fmt.Println(C_Prime_Plus)

}
