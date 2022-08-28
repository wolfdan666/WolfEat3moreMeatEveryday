package main

import "sort"

// 链接：https://leetcode.cn/problems/factorial-trailing-zeroes/solution/jie-cheng-hou-de-ling-by-leetcode-soluti-1egk/
func zeta(n int) (res int) {
	for n > 0 {
		n /= 5
		res += n
	}
	return
}

func nx(k int) int {
	return sort.Search(5*k, func(x int) bool { return zeta(x) >= k })
}

// preimageSizeFZF 感觉有点像算5的因子的个数，但是数据范围又有点大，想不太出来，看题解吧，学习一下
// 链接：https://leetcode.cn/problems/preimage-size-of-factorial-zeroes-function/solution/jie-cheng-han-shu-hou-k-ge-ling-by-leetc-n6vj/
func preimageSizeFZF(k int) int {
	return nx(k+1) - nx(k)
}
