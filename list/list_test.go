package list

import (
	"errors"
	"fmt"
	"testing"
)

type LNode struct {
	data int
	next *LNode
}

func Test_list(t *testing.T) {
	fmt.Println(10 % 10)
	// LA := InitList()
	// LB := InitList()
	// // generate two List
	// for i := 1; i < 5; i++ {
	// 	InsertElem(LA, i, i)
	// 	InsertElem(LB, i*2, i)
	// }
	// PrintList(LA)
	// PrintList(LB)
	// LC := MergeList(LA, LB)
	// PrintList(LC)
	// fmt.Println("delete LC 8 node")
	// DeleteElem(LC, 8)
	// PrintList(LC)
}

func InitList() *LNode {
	head := &LNode{
		data: 0,
		next: nil,
	}
	return head
}

func IsEmpty(L *LNode) bool {
	if L.next == nil && L != nil {
		return true
	}
	return false
}

func PrintList(L *LNode) {
	fmt.Printf("len: %d # ", GetLen(L))
	prt := L.next
	for {
		if prt == nil {
			fmt.Println()
			return
		}
		fmt.Printf("%v ", prt.data)
		prt = prt.next
	}
}

func GetElem(L *LNode, position int) (*LNode, error) {
	if IsEmpty(L) {
		return nil, errors.New("Empty list")
	}
	ptrNode := L.next
	j := 1
	for ptrNode != nil && j < position {
		ptrNode = ptrNode.next
		j++
	}
	if ptrNode == nil || j > position {
		return nil, errors.New("node does not exist")
	}
	return ptrNode, nil
}

func GetHeadElem(L *LNode) (int, error) {
	if !IsEmpty(L) {
		return L.next.data, nil
	}
	return -1, errors.New("Empty List")
}

func GetLen(L *LNode) int {
	len := 0
	prt := L
	for prt.next != nil {
		prt = prt.next
		len++
	}
	L.data = len
	return len
}

func InsertElem(L *LNode, data int, position int) error {
	if position > GetLen(L)+1 {
		return errors.New("position overflow")
	}
	InsertNode := &LNode{data: data}
	ptr := L
	n := 1
	for n < position {
		ptr = ptr.next
		n++
	}
	InsertNode.next = ptr.next
	ptr.next = InsertNode
	GetLen(L)
	return nil
}

func DeleteElem(L *LNode, position int) error {
	if position < 1 || position > GetLen(L) {
		return errors.New("wrong position")
	}
	ptr := L
	n := 1
	for n < position {
		ptr = ptr.next
		n++
	}
	ptr.next = ptr.next.next
	GetLen(L)
	return nil
}

func MergeList(LA, LB *LNode) *LNode {
	/*
		定义三个可移动的指针la,lb,lc
		每次插入成功移动相应的指针指向下一个待比较节点
	*/
	la := LA.next
	lb := LB.next
	LC := InitList()
	lc := LC
	i := 1
	for la != nil && lb != nil {
		if la.data <= lb.data {
			InsertElem(LC, la.data, i)
			fmt.Println("la<=lb")
			PrintList(LC)
			la = la.next
			lc = lc.next
			i++
		} else {
			InsertElem(LC, lb.data, i)
			fmt.Println("la>lb")
			PrintList(LC)
			lb = lb.next
			lc = lc.next
			i++
		}
	}
	if la != nil {
		fmt.Println("la!=nil")
		lc.next = la
	}
	if lb != nil {
		fmt.Println("lb!=nil")
		lc.next = lb
	}
	return LC
}
