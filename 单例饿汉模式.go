//go:build ignore

package main

import "fmt"

//"fmt"
//"container/list"
//"sort"
//"math/rand"
//"math"
//"strings"
type Hungry struct {
}

var hungry *Hungry = new(Hungry)

func getInstance() *Hungry {
	return hungry
}
func (it *Hungry) test() {
	fmt.Println("22222")
}

func main() {
	tmp := getInstance()
	tmp.test()
}
