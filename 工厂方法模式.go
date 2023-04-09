//go:build ignore

package main

import (
	"fmt"
	//"container/list"
	//"sort"
	//"math/rand"
	//"math"
	//"strings"
)

type AbstractFruit interface {
	ShowName()
}
type Apple struct {
}

func (apple *Apple) ShowName() {
	fmt.Println("im apple")
}

type Banana struct {
}

func (banana *Banana) ShowName() {
	fmt.Println("im banana")
}

type AbstractFactory interface {
	CreateFruit() AbstractFruit
}
type AppleFactory struct {
}

func (applefactory *AppleFactory) CreateFruit() AbstractFruit {
	return new(Apple)
}

type BananaFactory struct {
}

func (banana *Banana) CreateFruit() AbstractFruit {
	return new(Banana)
}
func main() {
	var factory AbstractFactory
	var fruit AbstractFruit
	factory = new(AppleFactory)
	fruit = factory.CreateFruit()
	fruit.ShowName()
}
