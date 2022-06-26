package main

import (
	"fmt"
	"math/rand"
)

type Solution struct {
	b2w   map[int]int
	bound int
}

func Constructor(n int, blacklist []int) Solution {
	m := len(blacklist)
	bound := n - m
	black := map[int]bool{}
	for _, b := range blacklist {
		// 只映射黑名单里面值小于 bound 的值
		if b >= bound {
			black[b] = true
		}
	}

	b2w := make(map[int]int, m-len(black))
	w := bound
	for _, b := range blacklist {
		if b < bound {
			for black[w] {
				w++
			}
			b2w[b] = w
			w++
		}
	}
	return Solution{b2w, bound}
}

func (s *Solution) Pick() int {
	x := rand.Intn(s.bound)
	if s.b2w[x] > 0 {
		return s.b2w[x]
	}
	return x
}

// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/random-pick-with-blacklist/solution/hei-ming-dan-zhong-de-sui-ji-shu-by-leet-cyrx/

/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(n, blacklist);
 * param_1 := obj.Pick();
 */

func main() {
	// n := 7
	// blacklist := []int{2, 3, 5}
	n := 4
	blacklist := []int{2, 1}
	obj := Constructor(n, blacklist)
	for i := 0; i < 2*n; i++ {
		fmt.Println(obj.Pick())
	}
}
